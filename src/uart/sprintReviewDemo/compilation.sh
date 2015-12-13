arm-linux-gnueabi-gcc-5 -Wall -march=armv7-a -I ../../../lib/libpcap/include/ -L ../../../lib/libpcap/lib/ *.c -o demoBT.elf -pthread -lpcap
