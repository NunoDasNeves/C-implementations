// HashTable.c
// My Hash Table ADT implementation
// by Nuno Das Neves
//
// Features:
// Automatically resizing
// Maps key strings to ints

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "HashTable.h"

// why would you want a key this long
#define MAX_KEY_LENGTH 1024
// TODO adjust these:
// starting size for our array
#define INIT_BUCKETS 32
// n/k (items/buckets) ratio
#define ITEM_BUCKET_THRESHOLD 2.0f
// not sure how this should be done exactly?
#define BUCKET_INC 16

typedef _HTnode * Node;

struct _HTnode {
    HTableKey key;
    HTableItem val;
    Node next;
}

struct _HTableRep {
    // we will have an array of nodes for our representation
    Node *list;
    // these are distinct! Watch out bro.
    u_int32_t buckets;  // size of our Nodes array
    u_int32_t items;    // total number of Nodes
} htRep;

// handy statics
static typedef u_int32_t HTIndex;

static Node createNode(HTableKey newKey, HTableItem newItem);
static void freeNode(Node N);
static u_int32_t hash(HTable T, HTableKey key);
static void resize(HTable T, HTableKey key);

// Create a new table
HTable HTableNew() 
{
    HTable T = malloc(sizeof(struct _HTableRep));
    T->list = malloc(sizeof(struct _HTnode)*INIT_BUCKETS);
    T->buckets = INIT_BUCKETS;
    // initialize all buckets to null
    int i;
    for (i=0;i<T->buckets;i++) T->list[i] = NULL;
    T->items = 0;
    return T;
}

// Return how many values are currently stored in the table
int HTableGetSize(HTable T) 
{
    return T->items;
}

// Insert a new value into the table with the specified key
void HTableInsert(HTable T, HTableKey newKey, HTableItem newItem) 
{
    HTIndex index = hash(newKey);
    if (
    
}

// Look up a value based on a key
HTableItem HTableLookup(HTable T, HTableKey theKey)
{
    return 0;
}

// Delete a key and associated value from the table
void HTableRemove(HTable T, HTableKey delKey)
{

}

// Destroy the table and free associated memory
void HTableFree(HTable T)
{
    free(T);
}

static void freeNode(Node N) {
    free(N->key);
    free(N);
}

// just creates a new Node for us to use
static Node createNode(HTableKey newKey, HTableItem newItem)
{
    Node N = malloc(sizeof(struct _HTnode));
    N->item = newItem;
    // need to add 1 for the terminating /0
    N->key = malloc(strlen(newKey)*sizeof(char) + 1);
    strcpy(N->key, newKey);
    N->next = NULL;
    return N;
}

// simple hash function for now
static HTIndex hash(HTable T, HTableKey key)
{
    int i=0;
    u_int32_t tot=0;
    // just add up all the character values in the key
    while (key[i] != '\0') {
        tot += key[i];
        i++;
    }
    //return the mod so it gives us an index to our array
    return tot%T->buckets;
}
