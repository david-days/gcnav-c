#!/usr/bin/make -f

SHELL = /bin/sh

CC              = gcc
FLAGS           =
CFLAGS          = -I./include -fPIC -g -Wall -Wextra
LDFLAGS         = -shared
DEBUGFLAGS      = -O0 -D
RELEASEFLAGS    = -O2 -D

SRCDIR = $(CURDIR)/src
OUTPUTDIR = $(CURDIR)/bin
INCLUDEDIR = $(CURDIR)/include

export OUTPUTDIR

TARGET_LIB  = libgraphcut.so
SOURCES = $(shell find $(SRCDIR) -name '*.c')
HEADERS = $(shell find $(INCLUDEDIR) -name '*.h')
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OUTPUTDIR)/%.o, $(SOURCES))
BINDIRS = $(dir $(OBJECTS))

VPATH = src:include:bin

all:  buildbin utils structs

.PHONY: utils
utils: buildbin
	cd $(SRCDIR)/utils && $(MAKE)

.PHONY: structs
structs: buildbin
	cd $(SRCDIR)/structs && $(MAKE)

.PHONY: buildbin
buildbin:
	@ mkdir -p $(BINDIRS)
	@ mkdir -p $(OUTPUTDIR)/test

.PHONY: test
test: all
	cd test && $(MAKE)

print-% :
	@echo $* = $($*)

.PHONY: clean
clean:
	@find -type f -iname '*.o' -delete
