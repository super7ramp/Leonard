parser : parser.o  main.o
	gcc -o parser parser.o main.o
	
parser.o : parser.c 
	gcc -o parser.o -c parser.c -Wall

main.o : main.c parser.h
	gcc -o main.o -c main.c -Wall

clean:
	rm -f *.o core
	rm -f *~ core
