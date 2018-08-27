CFLAGS=-g

all: anothertest

anothertest: anothertest.o
	gcc anothertest.o -o anothertest
	
anothertest.o: anothertest.c
	gcc -c anothertest.c
	
clean:
	rm –f *.o anothertest