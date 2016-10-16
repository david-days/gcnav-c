#!/usr/bin/make -f

SHELL = /bin/sh

OUTPUTDIR ?= ../../bin
BINDIR = $(OUTPUTDIR)/structs

CC              = gcc
FLAGS           =
VPATH		= ./:../../include:$(OUTPUTDIR)
CFLAGS          = -I../../include -Wall -c

SOURCES = $(shell echo *.c)
OBJECTS = $(SOURCES:.c=.o)

all:  queue.o stack.o unionfind.o

queue.o : queue.c structs/queue.h
	$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

stack.o : stack.c structs/stack.h
	$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

unionfind.o : unionfind.c structs/unionfind.h
	$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

.PHONY: clean
clean:
	@find -type f $(BINDIR) -name '*.o' -delete


