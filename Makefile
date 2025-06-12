CC=gcc
CFLAGS=-g -O0 -Wall -Wextra -Wshadow -Wunreachable-code
OBJS=objs/main.o

trc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

objs/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^



install::
	cp -v -p trc /usr/bin

uninstall::
	rm /usr/bin/trc


clean::
	rm $(OBJS) trc
