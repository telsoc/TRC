CC=gcc
CFLAGS=-g -O0 -Wall -Wextra -Wshadow -Wunreachable-code
OBJS=objs/main.o objs/server.o objs/client.o


trc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

objs/main.o: src/main.c
	$(CC) $(CFLAGS) -c -o $@ $^

objs/server.o: src/socket/server.c
	$(CC) $(CFLAGS) -c -o $@ $^

objs/client.o: src/socket/client.c
	$(CC) $(CFLAGS) -c -o $@ $^


install::
	cp -v -p objs/trc /usr/bin

uninstall::
	rm /usr/bin/trc


clean::
	rm $(OBJS) objs/trc
