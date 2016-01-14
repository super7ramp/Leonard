CC=arm-linux-gnueabi-gcc
CFLAGS=-W -Wall
ARCH=armv7-a
LFLAGS=-lpthread -lpcap -L ../../lib/libpcap/lib
SRC=at-commands.c message_drone.c at-sender.c navdata_controller.c spoof_udp.c
INCLUDE = -I $(shell pwd)/../../lib/libpcap/include
OBJ=$(SRC:.c=.o)
EXEC=test_com.elf


all:$(EXEC) 
	@echo $(INCLUDE)

com_lib: $(OBJ)	

test_navdata: $(OBJ) test_navdata.o
	$(CC) $(CFLAGS) -march=$(ARCH) -o $@ $^ $(INCLUDE) $(LFLAGS)

$(EXEC):$(OBJ) test-message_drone.o
	$(CC) $(CFLAGS) -march=$(ARCH) -o $@ $^ $(INCLUDE) $(LFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -march=$(ARCH) -c $< -o $@ $(INCLUDE) $(LFLAGS)

clean:
	rm -rf *.o *~ *.elf
