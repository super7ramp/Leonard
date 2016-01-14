CC=arm-linux-gnueabi-gcc
CFLAGS=-W -Wall
ARCH=armv7-a
INCLUDE = -I../../lib/libpcap/include 
SRC=$(wildcard *.c) ./KCG/system_state_machine.c ./KCG/kcg_types.c
OBJ=$(SRC:.c=.o)
STATIC=../../lib/libpcap/lib/libpcap.a

all:$(OBJ)
	
%.o: %.c  
	$(CC) $(CFLAGS) -march=$(ARCH) -c $< $(INCLUDE) -o $@ 

clean:
	rm -rf *.o *~ *.elf
