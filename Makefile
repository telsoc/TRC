CC=gcc
CFLAGS=-g -O0 -Wall -Wextra -Wshadow -Wunreachable-code
OBJS=objs/main.o objs/socket.o objs/client.o


trc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

objs/main.o: src/main.c
	$(CC) $(CFLAGS) -c -o $@ $^

objs/socket.o: src/socket/socket.c
	$(CC) $(CFLAGS) -c -o $@ $^

objs/client.o: src/socket/client.c
	$(CC) $(CFLAGS) -c -o $@ $^


install::
	cp -v -p trc /usr/bin

uninstall::
	rm /usr/bin/trc


clean::
	rm $(OBJS) trc
