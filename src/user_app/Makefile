CC=arm-linux-gnueabi-gcc
CFLAGS=-W -Wall
ARCH=armv7-a
LFLAGS=-lpthread -lpcap -L ../../lib/libpcap/lib
SRC= $(wildcard *.c)
OBJ=$(SRC:.c=.o)
EXEC=test_com.elf


all:$(EXEC) 

$(EXEC):$(OBJ)
	$(CC) $(CFLAGS) -march=$(ARCH) -o $@ $^ $(LFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -march=$(ARCH) -c $< -o $@ $(LFLAGS)

clean:
	rm -rf *.o *~ *.elf
