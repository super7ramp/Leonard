parser : parser.o localisation.o  main.o
	gcc -o parser parser.o localisation.o main.o
	
localisation.o : localisation.c 
	gcc -o localisation.o -c localisation.c -Wall

parser.o : parser.c 
	gcc -o parser.o -c parser.c -Wall
	
main.o : main.c parser.h localisation.h parameters.h
	gcc -o main.o -c main.c -Wall

clean:
	rm -f *.o core
	rm -f *~ core
