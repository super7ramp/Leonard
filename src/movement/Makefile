CC=arm-linux-gnueabi-gcc
CFLAGS=-W -Wall
ARCH=armv7-a
LFLAGS=-lpthread
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)


all:$(OBJ)

%.o: %.c %.h parameters.h
	$(CC) $(CFLAGS) -march=$(ARCH) -c $< -o $@ $(LFLAGS)

clean:
	rm -rf *.o *~ *.elf
