# Edit CC with your cross-compiler before compiling for the drone
CC=arm-linux-gnueabi-gcc 
CFLAGS=-Wall -march=armv7-a
BASEDIR=$(shell pwd)
SRCDIR=$(BASEDIR)/src
TESTDIR=$(BASEDIR)/src/tests
BUILDDIR=$(BASEDIR)/build
DOCDIR=$(BASEDIR)/doc

all: directories tests

directories:
	cd $(BASEDIR)
	mkdir -p $(BUILDDIR)

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
	rm -f $(TESTDIR)/*.o
	rm -rf $(DOCDIR)/html
