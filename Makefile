CC=gcc
CFLAGS=-g -O0 -Wall -Wextra -Wshadow -Wunreachable-code
OBJS=objs/main.o objs/client.o objs/server.o
VPATH=src src/dummy


objs/trc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

objs/%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<


install::
	cp -v -p trc /usr/bin

uninstall::
	rm /usr/bin/trc


clean::
	rm $(OBJS) objs/trc
