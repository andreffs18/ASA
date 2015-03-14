OBJS = main.o
CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -f *.o *~ main
	