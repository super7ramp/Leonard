CC=arm-linux-gnueabi-gcc
CFLAGS=-W -Wall
ARCH=armv7-a
LFLAGS =-lm
SRC=map_common.c map_reader.c shortest_path.c
OBJ=$(SRC:.c=.o)
EXEC=test_dijkstra


all:$(EXEC)

shortest_path_lib:$(OBJ) 

$(EXEC): $(OBJ) test_dijkstra.o
	$(CC) $(CFLAGS) -march=$(ARCH) -c $< -o $@ -lm
	
%.o: %.c %.h 
	$(CC) $(CFLAGS) -march=$(ARCH) -c $< -o $@ -lm

clean:
	rm -rf *.o *~ *.elf
