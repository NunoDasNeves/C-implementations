# my hashtable implementation

CC=gcc
CFLAGS=-Wall -Werror -gdwarf-2
LDFLAGS=

all: testHashTable

testHashTable : testHashTable.o HashTable.o

testHashTable.o : testHashTable.c
HashTable.o : HashTable.c HashTable.h

clean:
	rm -f testHashTable *.o
