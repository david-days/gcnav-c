#!/usr/bin/make -f

SHELL = /bin/sh

CC              = gcc
FLAGS           =
VPATH		= src:include:../graphcut/include
CFLAGS          = -I../graphcut/include -I./include -Wall

SOURCES = $(shell echo *.c)
OBJECTS = $(SOURCES:.c=.o)

all:  edgeutils.o mathutils.o

edgeutils.o : edgeutils.c utils/edgeutils.h utils/mathutils.h
	$(CC) $(CFLAGS) $< -o $@

mathutils.o : mathutils.c utils/mathutils.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)


