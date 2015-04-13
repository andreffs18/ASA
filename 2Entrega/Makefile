OBJS = main.o
CC = g++
CFLAGS = -O3 -Wall -c
LFLAGS = -lm

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -f *.o *~ main
	