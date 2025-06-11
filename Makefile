CC=gcc
CFLAGS=-g -O0
OBJS=main.o


trc: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $^


clean::
	rm $(OBJS)
