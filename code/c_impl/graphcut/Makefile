#!/usr/bin/make -f

SHELL = /bin/sh

CC              = gcc
FLAGS           =
CFLAGS          = -fPIC -g -Wall -Wextra
LDFLAGS         = -shared
DEBUGFLAGS      = -O0 -D
RELEASEFLAGS    = -O2 -D

TARGET_LIB  = libgraphcut.so
SOURCES = $(shell echo src/*.c)
HEADERS = $(shell echo include/*.h)
OBJECTS = $(SOURCES:.c=.0)

PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin

all:  $(TARGET_LIB)

$(TARGET_LIB):  $(OBJECTS)
    $(CC) $(FLAGS) $(CFLAGS) $(DEBUGFLAGS) $(LDFLAGS) -o $(TARGET_LIB) $(OBJECTS)

clean:
    rm -f $(OBJECTS) $(TARGET_LIB)


