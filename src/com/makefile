pcCom : sender.o receiver.o pcCom.o 
	gcc -o pcCom sender.o receiver.o pcCom.o -lpthread
	
com : sender.o receiver.o com.o
	gcc -o com sender.o receiver.o com.o
	
sender.o : sender.c 
	gcc -o sender.o -c sender.c -Wall

receiver.o : receiver.c 
	gcc -o receiver.o -c receiver.c -Wall
	
com.o : receiver.h sender.h
	gcc -o com.o -c com.c -Wall

pcCom.o : receiver.h sender.h params.h
	gcc -o pcCom.o -c pcCom.c -Wall

clean:
	rm -f *.o core
	rm -f *~ core
