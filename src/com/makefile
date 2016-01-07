pcCom : sender.o receiver.o pcCom.o 
	gcc -o pcCom sender.o receiver.o pcCom.o -lpthread
	
test : sender.o receiver.o test.o
	gcc -o test sender.o receiver.o test.o
	
sender.o : sender.c 
	gcc -o sender.o -c sender.c -Wall

receiver.o : receiver.c 
	gcc -o receiver.o -c receiver.c -Wall
	
test.o : receiver.h sender.h
	gcc -o test.o -c test.c -Wall

pcCom.o : receiver.h sender.h params.h
	gcc -o pcCom.o -c pcCom.c -Wall

clean:
	rm -f *.o core
	rm -f *~ core
