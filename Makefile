CC=gcc
CFLAGS=-g -O0 -Wall -Wextra -Wshadow -Wunreachable-code
OBJS=objs/main.o


objs/trc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

<<<<<<< Updated upstream
objs/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

=======

objs/%.o: src/socket/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

objs/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^
>>>>>>> Stashed changes


install::
	cp -v -p trc /usr/bin

uninstall::
	rm /usr/bin/trc


clean::
	rm $(OBJS) trc
