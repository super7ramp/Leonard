CC=arm-linux-gnueabi-gcc
CFLAGS=-W -Wall
ARCH=armv7-a
LFLAGS =-lpthread
INCLUDE = -I ../../lib/libpcap/include 
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)


all:$(OBJ)
	
%.o: %.c %.h 
	$(CC) $(CFLAGS) $(INCLUDE) -march=$(ARCH) -c $< -o $@ -lm

clean:
	rm -rf *.o *~ *.elf
