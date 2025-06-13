CC=gcc
CFLAGS=-g -O0 -Wall -Wextra -Wshadow -Wunreachable-code
OBJS=build/objs/main.o build/objs/client.o build/objs/server.o
VPATH=src src/dummy


build/objs/trc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

build/objs/%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<


install::
	cp -v -p objs/trc /usr/bin

uninstall::
	rm /usr/bin/trc


clean::
	rm $(OBJS) objs/trc
