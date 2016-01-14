# Edit CC with your cross-compiler before compiling for the drone
CC=arm-linux-gnueabi-gcc 
CFLAGS=-Wall
ARCH=armv7-a
LIB = -lpthread -lpcap -L lib/libpcap/lib -lm
INCLUDE = -I lib/libpcap/include 

BASEDIR=$(shell pwd)
BUILDDIR=$(BASEDIR)/build
SRCDIR=$(BASEDIR)/src

TESTDIR=$(SRCDIR)/tests
BLUETOOTHDIR=$(SRCDIR)/uart
COMDIR=$(SRCDIR)/com
MOVEMENTDIR=$(SRCDIR)/movement
STATEMACHINEDIR=$(SRCDIR)/state_machine
SHORTESTPATHDIR=$(SRCDIR)/shortest_path
KCGDIR=$(STATEMACHINEDIR)/KCG
EXEC=Control_Law.elf

OBJS =$(wildcard $(BLUETOOTHDIR)/*.o) $(wildcard $(COMDIR)/*.o) $(wildcard $(MOVEMENTDIR)/*.o) $(wildcard $(STATEMACHINEDIR)/*.o) $(wildcard $(SHORTESTPATHDIR)/*.o) $(wildcard $(KCGDIR)/*.o)


DOCDIR=$(BASEDIR)/doc

all: $(EXEC)

directories:
	cd $(BASEDIR)
	mkdir -p $(BUILDDIR)

$(EXEC): bluetooth_lib movement_lib com_lib shortest_path_lib state_machine_lib
	$(CC) $(CFLAGS) -march=$(ARCH) $(OBJS) $(LIB) -o $@

bluetooth_lib:
	cd $(BLUETOOTHDIR) && $(MAKE) bluetooth_lib

movement_lib:
	cd $(MOVEMENTDIR) && $(MAKE) 

com_lib:
	cd $(COMDIR) && $(MAKE) com_lib

state_machine_lib:
	cd $(STATEMACHINEDIR) && $(MAKE)

shortest_path_lib:
	cd $(SHORTESTPATHDIR) && $(MAKE) shortest_path_lib

.PHONY: doc
doc:
	doxygen $(SRCDIR)/Doxyfile

tests: $(SRCDIR)/at-commands.o $(SRCDIR)/sender.o $(SRCDIR)/message_drone.o $(TESTDIR)/test-at-commands.o $(TESTDIR)/test-sender.o $(TESTDIR)/test-message_drone.o
	$(CC) $(CFLAGS) $(TESTDIR)/test-at-commands.o $(SRCDIR)/at-commands.o -o $(BUILDDIR)/test-at-commands
	$(CC) $(CFLAGS) $(TESTDIR)/test-sender.o $(SRCDIR)/sender.o -o $(BUILDDIR)/test-sender
	$(CC) $(CFLAGS) $(TESTDIR)/test-message_drone.o $(SRCDIR)/message_drone.o $(SRCDIR)/at-commands.o $(SRCDIR)/sender.o -o $(BUILDDIR)/test-message_drone

at-commands.o:
	$(CC) $(CFLAGS) -c at-commands.c

test-at-commands.o: $(SRCDIR)/at-commands.c $(TESTDIR)/test-at-commands.c
	$(CC) $(CFLAGS) -c at-commands.c test-at-commands.c

test-sender.o: $(SRCDIR)/sender.c $(TESTDIR)/test-sender.c
	$(CC) $(CFLAGS) -c sender.c test-sender.c

test-message_drone.o: $(SRCDIR)/message_drone.c $(SRCDIR)/at-commands.c $(SRCDIR)/sender.c $(TESTDIR)/test-message_drone.c
	$(CC) $(CFLAGS) -c message_drone.c at-commands.c sender.c test-message_drone.c

.PHONY: clean
clean:
	rm -f $(BUILDDIR)/*
	rm -f $(SRCDIR)/*.o
	rm -f $(BLUETOOTHDIR)/*.o
	rm -f $(COMDIR)/*.o
	rm -f $(MOVEMENTDIR)/*.o
	rm -f $(SHORTESTPATHDIR)/*.o
	rm -f $(STATEMACHINEDIR)/*.o
	rm -f $(KCGDIR)
	rm -f $(TESTDIR)/*.o
	rm -f $(DOCDIR)/html
	rm -rf Control_Law.elf
