CC=arm-linux-gnueabi-gcc
CFLAGS=-W -Wall
ARCH=armv7-a
LFLAGS=-lpthread
SRC=uart.c parser.c localisation.c display.c
OBJ=$(SRC:.c=.o)
EXEC=computeLocation.elf


all:$(EXEC) 

bluetooth_lib: $(OBJ)

$(EXEC):$(OBJ) main.o
	$(CC) $(CFLAGS) -march=$(ARCH) -o $@ $^ $(LFLAGS)

%.o: %.c %.h parameters.h
	$(CC) $(CFLAGS) -march=$(ARCH) -c $< -o $@ $(LFLAGS)

clean:
	rm -rf *.o *~ *.elf
