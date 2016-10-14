#!/usr/bin/make -f

SHELL = /bin/sh

CC              = gcc
FLAGS           =
VPATH		= graphcut:guidance:sensors:test
CFLAGS          = -I../graphcut/include -I./include -Wall

SOURCES = $(shell echo *.c)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all
all:
	cd graphcut && $(MAKE)   

.PHONY: test
test:
	cd graphcut && $(MAKE)
	cd test && $(MAKE)

.PHONY: clean
clean:
	find -type f -name '*.o' -print -delete


