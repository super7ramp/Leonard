CC=arm-linux-gnueabi-gcc
LFLAGS=-pthread
INCLUDE=-I ../../lib/libpcap/include
STATIC=../../lib/libpcap/lib/libpcap.a
CFLAGS=-W -Wall $(LFLAGS) $(INCLUDE)
ARCH=armv7-a
SRC=at-commands.c message_drone.c at-sender.c navdata_controller.c spoof_udp.c
OBJ=$(SRC:.c=.o)
EXEC=test_com.elf


all:$(EXEC) 
	@echo $(INCLUDE)

com_lib: $(OBJ)	

test_navdata: $(OBJ) test_navdata.o
	$(CC) $(CFLAGS) -march=$(ARCH) -o $@ $^ 

$(EXEC):$(OBJ) test-message_drone.o
	$(CC) $(CFLAGS) -march=$(ARCH) -o $@ $^ 

%.o: %.c %.h
	$(CC) $(CFLAGS) -march=$(ARCH) -c $< $(INCLUDE) -o $@

clean:
	rm -rf *.o *~ *.elf
