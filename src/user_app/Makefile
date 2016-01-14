CC=gcc
CFLAGS=-W -Wall
LFLAGS=-lpthread
SRC= $(wildcard *.c)
OBJ=$(SRC:.c=.o)
EXEC=test_com


all:$(EXEC) 

$(EXEC):$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o *~ 
