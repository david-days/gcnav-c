#!/usr/bin/make -f

SHELL = /bin/sh

CC              = gcc
FLAGS           =
VPATH		= ./:../../include
CFLAGS          = -I../../include -Wall -c

SOURCES = $(shell echo *.c)
OBJECTS = $(SOURCES:.c=.o)

all:  queue.o stack.o unionfind.o

queue.o : queue.c structs/queue.h
	$(CC) $(CFLAGS) $< -o $@

stack.o : stack.c structs/stack.h
	$(CC) $(CFLAGS) $< -o $@

unionfind.o : unionfind.c structs/unionfind.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)


