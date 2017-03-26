#!/usr/bin/make -f

SHELL = /bin/sh

CC              = gcc
FLAGS           =
VPATH		= ./:../../include
CFLAGS          = -I../../include -Wall -c

SOURCES = $(shell echo *.c)
OBJECTS = $(SOURCES:.c=.o)

all:  graphmgt.o

graphmgt.o : graphmgt.c gmgt/graphmgt.h graphstructs.h structs/unionfind.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)


