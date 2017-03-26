#!/usr/bin/make -f

SHELL = /bin/sh

OUTPUTDIR ?= ../../bin
BINDIR = $(OUTPUTDIR)/utils

CC              = gcc
FLAGS           =
VPATH		= ./:../../include:$(OUTPUTDIR)
CFLAGS          = -I../../include -Wall -c

SOURCES = $(shell echo *.c)
OBJECTS = $(SOURCES:.c=.o)

all:  edgeutils.o mathutils.o

edgeutils.o : edgeutils.c utils/edgeutils.h utils/mathutils.h
	$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

mathutils.o : mathutils.c utils/mathutils.h
	$(CC) $(CFLAGS) $< -o $(BINDIR)/$@

.PHONY: clean
clean:
	find -type f $(BINDIR) -iname '*.o' -delete


