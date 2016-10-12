# Ultimate Makefile v1.0.1 (C) 2016 Ivan Chebykin
# NOTE: GNU Make only

# Variables--------------------------------------------------------------------
PROJECT?=
INCLUDE_DIR?=
CC=clang++
CFLAGS?=-g -std=c++14 -Wall -I$(INCLUDE_DIR)
LDFLAGS?=

OBJEXT?=o
SRCEXT?=cpp

SRCDIR?=src
BUILDDIR?=Debug
OBJDIR?=obj

OBJPATH?=$(BUILDDIR)/$(OBJDIR)
TARGET?=$(BUILDDIR)/$(PROJECT)

SOURCES?=$(shell find $(SRCDIR) -type f -name "*.$(SRCEXT)")
OBJECTS?=$(patsubst $(SRCDIR)/%,$(OBJPATH)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

