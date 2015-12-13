sender.o : sender.c
	arm-linux-gnueabi-gcc -I ../../../lib/libpcap/include/ -L ../../../lib/libpcap/lib/ -march=armv7-a -c sender.c -o sender.o -pthread -lpcap

at-commands.o : at-commands.c
	arm-linux-gnueabi-gcc -I ../../../lib/libpcap/include/ -L ../../../lib/libpcap/lib/ -march=armv7-a -c at-commands.c -o at-commands.o -pthread -lpcap

message_drone.o : message_drone.c sender.o
	arm-linux-gnueabi-gcc -I ../../../lib/libpcap/include/ -L ../../../lib/libpcap/lib/ -march=armv7-a message_drone.c -o message_drone.o -pthread -lpcap

uart.o: uart.c
	arm-linux-gnueabi-gcc -I ../../../lib/libpcap/include/ -L ../../../lib/libpcap/lib/ -march=armv7-a uart.c -o uart.o -pthread -lpcap

all: message_drone.o uart.o at-commands.o sender.o
	arm-linux-gnueabi-gcc-5 -Wall -march=armv7-a -I ../../../lib/libpcap/include/ -L ../../../lib/libpcap/lib/ uart.o sender.o message_drone.o at-commands.o -o demoBT.elf -pthread -lpcap


clean:
	rm *.elf 2>/dev/null
	rm *.o 2>/dev/null
	rm *~ 2>/dev/null

