cd ttcn3
rm -r bin/
ttcn3_makefilegen -t TDT4290.tpd
cd bin
make all
