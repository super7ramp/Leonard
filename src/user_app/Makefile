CC=gcc
CFLAGS=-W -Wall
LFLAGS=-lpthread
SRC= $(wildcard *.c) 
OBJ=$(SRC:.c=.o)
EXEC=test_com

all:clean $(EXEC) 

$(EXEC):$(OBJ) tcp_com
	$(CC) $(CFLAGS) -o $@ $< tcp_receiver.o tcp_sender.o $(LFLAGS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

tcp_com: tcp_sender.o tcp_receiver.o

tcp_sender.o: ../com/tcp_sender.c
	$(CC) $(CFLAGS) -c $< -o $@

tcp_receiver.o: ../com/tcp_receiver.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o *~ 
