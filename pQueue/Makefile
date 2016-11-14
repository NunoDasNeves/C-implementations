
# my hashtable implementation

CC=gcc
CFLAGS=-Wall -Werror -gdwarf-2
LDFLAGS=

all: testPQueue

testPQueue : testPQueue.o PQueue.o

testPQueue.o : testPQueue.c
PQueue.o :  PQueue.c PQueue.h

clean:
	rm -f testPQueue *.o
