## To add a new file to the build system, write where
## you want it to be built at the end of OBJS (OBJS
## entries should be seperated by spaces). If you want
## a new directory to be searched during the build
## process, add it to the end of VPATH (also seperated
## by spaces).
##
## If anything breaks, or you don't understand what these
## comments are saying, ping vibe-876 (Camilla) a message.

CC=gcc
CFLAGS=-g -O0 -Wall -Wextra -Wshadow -Wunreachable-code -Wno-unused-parameter
OBJS=build/objs/main.o build/objs/cmd_procr.o build/objs/topology.o build/objs/init.o
VPATH=src src/socket src/utils src/guts


build/trc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

build/objs/%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

build/objs/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


install::
	cp -v -p build/trc /usr/bin

uninstall::
	rm /usr/bin/trc


clean::
	rm $(OBJS) build/trc
