CC=gcc
CFLAGS=-g -O0 -Wall -Wextra -Wshadow -Wunreachable-code
OBJS=build/objs/main.o
VPATH=src src/server


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
