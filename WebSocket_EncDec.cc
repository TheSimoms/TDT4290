/******************************************************************************
* Copyright (c) 2005, 2015  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
* Gabor Szalai
******************************************************************************/
//
//  File:               WebSocket_EncDec.cc
//  Prodnr:             CNL 113 782
//  Rev:                R2A


#include "WebSocket_Types.hh"
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>

static const unsigned char zero_data[]={0,0,0,0};
static const OCTETSTRING zero_oct=OCTETSTRING(4,&zero_data[0]);


namespace WebSocket__Types {

void do_mask(const unsigned char* key, const unsigned char* source, 
             unsigned char* target, size_t size){
  int key_idx=0;
  for(size_t i=0;i<size;i++){
    target[i]=source[i]^key[key_idx];
    key_idx++;
    key_idx&=0x3;
  }
}

void f__WebSocket__Encode(const WebSocket__PDU& pl__pdu, OCTETSTRING& pl__data,
                   const BOOLEAN& pl__gen__maks, const BOOLEAN& pl__auto__maks){
  TTCN_Buffer buff;
  unsigned char* data_ptr=NULL;
  size_t payload_size=0;
  if(pl__pdu.payload__data().ispresent()){
    if(pl__pdu.payload__data()().ischosen(WebSocket__payloads::ALT_data)){
      payload_size=pl__pdu.payload__data()().data().lengthof();
    } else {
      payload_size=2;
      if(pl__pdu.payload__data()().close__data().data().ispresent()){
        payload_size+=pl__pdu.payload__data()().close__data().data()().lengthof();
      }
    }
  }
  size_t data_size=14+payload_size; // max header size + payload size
  
  buff.get_end(data_ptr,data_size);
  unsigned char* begin_ptr=data_ptr;
  memset(data_ptr,0,data_size);

  *data_ptr|=((*((const unsigned char*)pl__pdu.fin__bit()))&0x1)<<7;
  *data_ptr|=((*((const unsigned char*)pl__pdu.rsv1__bit()))&0x1)<<6;
  *data_ptr|=((*((const unsigned char*)pl__pdu.rsv2__bit()))&0x1)<<5;
  *data_ptr|=((*((const unsigned char*)pl__pdu.rsv3__bit()))&0x1)<<4;
  *data_ptr|=((int)pl__pdu.opcode())&0xf;
  data_ptr++;

  *data_ptr|=((*((const unsigned char*)pl__pdu.mask__bit()))&0x1)<<7;

  // encode size
  if(payload_size<126){
    *data_ptr|=(payload_size&0x7);
    data_ptr++;
  } else if (payload_size<65536) { // 16 bit unsigned max
    size_t orig_p_size=payload_size; 
    *data_ptr|=126;
    data_ptr++;
    data_ptr[1]=orig_p_size&0xff;
    orig_p_size>>=8;
    data_ptr[0]=orig_p_size&0xff;
    data_ptr+=2;
  } else {
    size_t orig_p_size=payload_size; 
    *data_ptr|=127;
    data_ptr++;
    data_ptr[7]=orig_p_size&0xff;
    orig_p_size>>=8;
    data_ptr[6]=orig_p_size&0xff;
    orig_p_size>>=8;
    data_ptr[5]=orig_p_size&0xff;
    orig_p_size>>=8;
    data_ptr[4]=orig_p_size&0xff;
    orig_p_size>>=8;
    data_ptr[3]=orig_p_size&0xff;
    orig_p_size>>=8;
    data_ptr[2]=orig_p_size&0xff;
    orig_p_size>>=8;
    data_ptr[1]=orig_p_size&0xff;
    orig_p_size>>=8;
    data_ptr[0]=orig_p_size&0xff;
    data_ptr+=8;
  }
  
  unsigned char* mask_ptr=NULL;
  if(((*((const unsigned char*)pl__pdu.mask__bit()))&0x1) &&
      pl__gen__maks &&
      (!pl__pdu.masking__key().ispresent() || 
                                           pl__pdu.masking__key()()==zero_oct)){
    // generate masking key
    mask_ptr=data_ptr;
    OCTETSTRING mk=f__WebSocket__Generate__Masking__Key();
    memcpy(data_ptr,(const unsigned char *)mk,4);
    data_ptr+=4;
  } else if(pl__pdu.masking__key().ispresent()) { // use the provided key
    mask_ptr=data_ptr;
    memcpy(data_ptr,(const unsigned char *)pl__pdu.masking__key()(),4);
    data_ptr+=4;
  }
  
  if(pl__pdu.payload__data().ispresent()){
    if(pl__pdu.payload__data()().ischosen(WebSocket__payloads::ALT_data)){
      memcpy(data_ptr,
             (const unsigned char *)pl__pdu.payload__data()().data(),
             pl__pdu.payload__data()().data().lengthof());
    } else {
      int st_code=(int)pl__pdu.payload__data()().close__data().status__code();
      data_ptr[1]=st_code&0xFF;
      st_code>>=8;
      data_ptr[0]=st_code&0xFF;
      if(pl__pdu.payload__data()().close__data().data().ispresent()){
        memcpy(data_ptr+2, // skip status code
        (const unsigned char *)pl__pdu.payload__data()().close__data().data()(),
             pl__pdu.payload__data()().close__data().data()().lengthof());
      }
    }
  }
  
  if(mask_ptr && pl__auto__maks){ // apply mask
    do_mask(mask_ptr,data_ptr,data_ptr,payload_size);
  }
  
  buff.increase_length(data_ptr-begin_ptr+payload_size);
  buff.get_string(pl__data);
  
}

INTEGER f__WebSocket__Decode(const OCTETSTRING& pl__data, 
                        WebSocket__PDU& pl__pdu, const BOOLEAN& pl__auto__maks){
  size_t data_len=pl__data.lengthof();
  if(data_len>=2){
    const unsigned char* data_ptr=(const unsigned char*)pl__data;
    size_t base_length=(data_ptr[1]&0x80)?6:2;
    size_t payload_length=data_ptr[1]&0x7F;
    size_t len_len=0;
    if (payload_length==126) {
      if(data_len>=4){
        payload_length=(data_ptr[2]<<8)+data_ptr[3];
        len_len=2;
      } else {
        return 1; // NOT_MY_TYPE not enough bits in the buffer
      }
    } else if (payload_length==127) {
      if(data_len>=10){
        len_len=8;
        long long int large_payload_length=(((long long int)data_ptr[2])<<56)+
          (((long long int)data_ptr[3])<<48)+(((long long int)data_ptr[4])<<40)+
          (((long long int)data_ptr[5])<<32)+(((long long int)data_ptr[6])<<24)+
          (((long long int)data_ptr[7])<<16)+(((long long int)data_ptr[8])<<8)+
          (long long int)data_ptr[9];
        payload_length=large_payload_length;
        if(large_payload_length!=(long long int)payload_length){ // overflow
          TTCN_warning("The received WebSocket messages is too large");
          return 1; // NOT_MY_TYPE message too largo to handle
        }
      } else {
        return 1; // NOT_MY_TYPE not enough bits in the buffer
      }
    }
    
    if(data_len<(payload_length+base_length)){
      return 1; // NOT_MY_TYPE not enough bits in the buffer
    }
    
    // Now the decodeing can be started.
    unsigned char bit_temp;
    
    bit_temp=(data_ptr[0]>>7)&0x1;
    pl__pdu.fin__bit()=BITSTRING(1,&bit_temp);
    bit_temp=(data_ptr[0]>>6)&0x1;
    pl__pdu.rsv1__bit()=BITSTRING(1,&bit_temp);
    bit_temp=(data_ptr[0]>>5)&0x1;
    pl__pdu.rsv2__bit()=BITSTRING(1,&bit_temp);
    bit_temp=(data_ptr[0]>>4)&0x1;
    pl__pdu.rsv3__bit()=BITSTRING(1,&bit_temp);
    
    pl__pdu.opcode()=data_ptr[0]&0xf;
    
    bit_temp=(data_ptr[1]>>7)&0x1;
    bool masked=bit_temp;
    pl__pdu.mask__bit()=BITSTRING(1,&bit_temp);
    pl__pdu.payload__len()=payload_length;
    
    data_ptr+=len_len+2;
    
    unsigned char* unmasked=NULL;
    if(masked){
      pl__pdu.masking__key()=OCTETSTRING(4,data_ptr);
      if(pl__auto__maks && payload_length){
        unmasked=(unsigned char*)Malloc(payload_length*sizeof(unsigned char));
        do_mask(data_ptr,data_ptr+4,unmasked,payload_length);
        data_ptr=unmasked;
      } else {
        data_ptr+=4;
      }
    } else {
      pl__pdu.masking__key()=OMIT_VALUE;
    }
    
    if(payload_length){
      if(pl__pdu.opcode()==WebSocket__opcode::Connection__Close){
        if(payload_length>=2){
          pl__pdu.payload__data()().close__data().status__code()= 
                                                 (data_ptr[0]<<8) + data_ptr[1];
          if(payload_length>2){
            pl__pdu.payload__data()().close__data().data()()=
                                       OCTETSTRING(payload_length-2,data_ptr+2);
          } else {
            pl__pdu.payload__data()().close__data().data()=OMIT_VALUE;
          }
        } else {
          return 1; // NOT_MY_TYPE not enough bits in the buffer
        }
      } else {
        pl__pdu.payload__data()().data()=OCTETSTRING(payload_length,data_ptr);
      }
      
    } else {
      pl__pdu.payload__data()=OMIT_VALUE;
    }
    
    if(unmasked) {
      Free(unmasked);
    }
    
  } else {
    return 1; // NOT_MY_TYPE not enough bits in the buffer
  }
  return 0;
}

INTEGER f__WebSocket__calc__length(const OCTETSTRING& pl__data){
  size_t data_len=pl__data.lengthof();
  if(data_len>=2){
    const unsigned char* data_ptr=(const unsigned char*)pl__data;
    int base_length=(data_ptr[1]&0x80)?6:2;
    int payload_length=data_ptr[1]&0x7F;
    if(payload_length<126){
      return payload_length+base_length;
    } else if (payload_length==126) {
      if(data_len>=4){
        payload_length=(data_ptr[2]<<8)+data_ptr[3];
        return payload_length+base_length+2;
      }
    } else {
      if(data_len>=10){
        long long int large_payload_length=(((long long int)data_ptr[2])<<56)+
          (((long long int)data_ptr[3])<<48)+(((long long int)data_ptr[4])<<40)+
          (((long long int)data_ptr[5])<<32)+(((long long int)data_ptr[6])<<24)+
          (((long long int)data_ptr[7])<<16)+(((long long int)data_ptr[8])<<8)+
          (long long int)data_ptr[9]+(long long int)base_length+8;
        INTEGER large_ret_val;
        large_ret_val.set_long_long_val(large_payload_length);
        return large_ret_val;
      }
    }
  }
  return -1;
}

OCTETSTRING f__WebSocket__Generate__Masking__Key(){
  static bool inited=false;
  if(!inited){
    time_t t1;
    time(&t1);
	  srand48((long) t1);
    inited=true;
  }
  unsigned char mkey[4];
  long int key=mrand48();
  mkey[0]= key & 0xFF;
  key>>=8;
  mkey[1]= key & 0xFF;
  key>>=8;
  mkey[2]= key & 0xFF;
  key>>=8;
  mkey[3]= key & 0xFF;
  return OCTETSTRING(4,&mkey[0]);
}


}

