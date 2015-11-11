cd ttcn3
rm -r bin/
libs/ttcn3/bin/ttcn3_makefilegen -t TDT4290.tpd
cd bin
make all
