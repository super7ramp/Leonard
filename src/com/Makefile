CC=arm-linux-gnueabi-gcc
LFLAGS=-pthread -lpcap -L ../../lib/libpcap/lib
INCLUDE=-I ../../lib/libpcap/include
STATIC=../../lib/libpcap/lib/libpcap.a
CFLAGS=-W -Wall $(LFLAGS) $(INCLUDE)
ARCH=armv7-a
SRC=at-commands.c message_drone.c at-sender.c navdata_controller.c spoof_udp.c tcp_sender.c tcp_receiver.c
OBJ=$(SRC:.c=.o)
EXEC=test_com.elf


all:$(EXEC) 

com_lib: $(OBJ)	

test_navdata: $(OBJ) test_navdata.o
	$(CC) $(CFLAGS) -march=$(ARCH) -o $@ $(LFLAGS) $^ 

$(EXEC):$(OBJ) test-message_drone.o
	$(CC) $(CFLAGS) -march=$(ARCH) -o $@ $^ 

%.o: %.c %.h
	$(CC) $(CFLAGS) -march=$(ARCH) -c $< $(INCLUDE) -o $@

clean:
	rm -rf *.o *~ *.elf
