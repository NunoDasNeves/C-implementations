// testHashTable.c
// My Hash Table ADT implementation
// by Nuno Das Neves
//
// This runs a bunch of unit tests on the HashTable ADT 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "HashTable.h"

// length 7
#define KEYLIST1 "donkey","horse","manny-kin","pant{@${}@#*%@!1aloon","waspjimmy","franklinbasket","wow this 'aargh' focacia bread apricot"
// lenght 32
#define KEYLIST2 "0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"

#define TRUE 1
#define FALSE 0

int main () {
    
    printf ("Basic initialization and freeing tests\n");
    // initializing and testing basics
    HTable T = HTableNew();
    assert(T != NULL);
    assert(HTableGetSize(T) == 0);
    assert(HTableKeyExists(T, "pants") == FALSE);
    HTableFree(T);
    
    // again, this time we don't free cos we're gonna do more tests
    T = HTableNew();
    assert(T != NULL);
    assert(HTableGetSize(T) == 0);
    
    printf ("Basic insert/remove tests\n");
    // basic insert and remove tests
    HTableInsert(T, "key1", 4);
    assert(HTableGetSize(T) == 1);
    assert(HTableKeyExists(T, "key1") == TRUE);
    assert(HTableLookup(T, "key1") == 4);
    HTableRemove(T, "key1");
    assert(HTableKeyExists(T, "key1") == FALSE);
    assert(HTableGetSize(T) == 0);
   
    HTableInsert(T, "", 42);
    assert(HTableGetSize(T) == 1);
    assert(HTableLookup(T, "") == 42);
    HTableInsert(T, "", 69);
    assert(HTableGetSize(T) == 1);
    assert(HTableLookup(T, "") == 69);

    HTableInsert(T, "@", 9001);
    assert(HTableGetSize(T) == 2);
    assert(HTableKeyExists(T, "@") == TRUE);
    assert(HTableLookup(T, "@") == 9001);
    HTableRemove(T, "@");
    assert(HTableGetSize(T) == 1);
    assert(HTableKeyExists(T, "@") == FALSE);
    HTableFree(T);
    
    printf ("Testing with 7 keys\n");
    // more tests with a bunch of keys and random edge cases and idk 
    T = HTableNew();
    assert(T != NULL);
    assert(HTableGetSize(T) == 0);
    HTableKey list1[] = {KEYLIST1};
    int i;
    for (i=0;i<7;i++) HTableInsert(T, list1[i], i); 
    for (i=0;i<7;i++) assert(HTableLookup(T, list1[i]) == i); 
    assert(HTableGetSize(T) == 7);
    HTableFree(T);

    printf ("Passed all tests! Woohoo!\n");

    return 0;
}
