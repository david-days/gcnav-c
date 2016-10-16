#!/usr/bin/make -f

SHELL = /bin/sh

OUTPUTDIR ?= ../bin
BINDIR = $(OUTPUTDIR)/test

CC              = gcc
FLAGS           =
VPATH		= src:../src:include:../include:$(OUTPUTDIR)
CFLAGS          = -I../include -I./include -Wall

SOURCEDIR = src

SOURCES = $(shell echo *.c)
OBJECTS = $(SOURCES:.c=.o)

all:  test-math
	@ $(BINDIR)/test-math

mathtest.o: mathtest.c include/testing.h
	$(CC) -c $(CFLAGS) $< -o $(BINDIR)/$@

.PHONY: test-math
test-math: $(BINDIR)/mathtest.o $(OUTPUTDIR)/utils/mathutils.o
	$(CC) $(BINDIR)/mathtest.o $(OUTPUTDIR)/utils/mathutils.o -o $(BINDIR)/$@

.PHONY: clean
clean:
	find -type f $(BINDIR) -iname '*.o' -delete


