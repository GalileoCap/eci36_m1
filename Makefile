#############################################################
# Config ####################################################

SRCD := src
BUILDD := build
INCLUDED := $(SRCD)/include

BIN := build/main
CSRC := $(wildcard $(SRCD)/*.cc) $(wildcard $(SRCD)/**/*.cc)

CC=g++
CFLAGS := -std=c++1z
CFLAGS += -O2
CFLAGS += -I$(INCLUDED)

.PHONY: default build clean
default: build

#############################################################
# Util targets ##############################################

#############################################################
# Main targets ##############################################

build:
	mkdir -p $(BUILDD)
	$(CC) $(CSRC) $(CFLAGS) -o $(BIN)

clean:
	rm -rf $(BUILDD)
