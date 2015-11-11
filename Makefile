# Edit CC with your cross-compiler before compiling for the drone
CC=gcc
CFLAGS=-Wall
BASEDIR=$(shell pwd)
SRCDIR=$(BASEDIR)/src
TESTDIR=$(BASEDIR)/src/tests
BUILDDIR=$(BASEDIR)/build

all: directories tests

directories:
	cd $(BASEDIR)
	mkdir -p $(BUILDDIR)

tests: $(SRCDIR)/at-commands.o $(SRCDIR)/sender.o $(TESTDIR)/test-at-commands.o $(TESTDIR)/test-sender.o
	$(CC) $(CFLAGS) $(TESTDIR)/test-at-commands.o $(SRCDIR)/at-commands.o -o $(BUILDDIR)/test-at-commands
	$(CC) $(CFLAGS) $(TESTDIR)/test-sender.o $(SRCDIR)/sender.o -o $(BUILDDIR)/test-sender

at-commands.o:
	$(CC) $(CFLAGS) -c at-commands.c

test-at-commands.o: $(SRCDIR)/at-commands.c $(TESTDIR)/test-at-commands.c
	$(CC) $(CFLAGS) -c at-commands.c test-at-commands.c

test-sender.o: $(SRCDIR)/sender.c $(TESTDIR)/test-sender.c
	$(CC) $(CFLAGS) -c sender.c test-sender.c


clean:
	rm $(BUILDDIR)/*
	rm $(SRCDIR)/*.o
	rm $(TESTDIR)/*.o
