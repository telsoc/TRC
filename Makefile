CC=gcc
CFLAGS=-g -O0 -Wall -Wextra -Wshadow -Wunreachable-code
OBJS=objs/main.o


trc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

objs/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^


clean::
	rm $(OBJS)
