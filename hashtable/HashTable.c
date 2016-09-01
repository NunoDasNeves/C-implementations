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

typedef struct _HTnode * Node;

struct _HTnode {
    HTableKey key;
    HTableItem val;
    Node next;
};

struct _HTRep {
    // we will have an array of nodes for our representation
    Node *list;
    // these are distinct! Watch out bro.
    u_int32_t buckets;  // size of our Nodes array
    u_int32_t items;    // total number of Nodes
};

// handy statics
typedef u_int32_t HTIndex;

static Node createNode(HTableKey newKey, HTableItem newItem);
static void freeNode(Node N);
static void freeBucket(Node N);
static u_int32_t hash(HTable T, HTableKey key);
static void resize(HTable T);

// Create a new table
HTable HTableNew() 
{
    HTable T = malloc(sizeof(struct _HTRep));
    T->list = malloc(sizeof(struct _HTnode) * INIT_BUCKETS);
    T->buckets = INIT_BUCKETS;
    T->items = 0;
    // initialize all buckets to null
    int i;
    for (i=0;i<T->buckets;i++) T->list[i] = NULL;
    return T;
}

// Return how many values are currently stored in the table
u_int32_t HTableGetSize(HTable T) 
{
    return T->items;
}

// Insert a new value into the table with the specified key
void HTableInsert(HTable T, HTableKey newKey, HTableItem newItem) 
{
    assert (T!=NULL);
    HTIndex index = hash(T, newKey);
    // loop through the list at that index, updating the key's value if it exists already
    Node * prev = &T->list[index];
    Node curr = T->list[index];
    while (curr != NULL) {
        if (strcmp(newKey, curr->key) == 0) {
            curr->val = newItem;
            return;
        }
        prev=&curr->next;
        curr=curr->next;
    }
    // if we got here, it doesn't exist! so create it
    Node new = createNode(newKey, newItem);
    // append to the end of the list we just traversed
    *prev = new;
    // increment our item count
    T->items++;
    // if our buckets are getting too full, resize
    // TODO 
    resize(T);
}

signed char HTableKeyExists(HTable T, HTableKey theKey) {
    assert (T!=NULL);
    HTIndex index = hash(T, theKey);
    // loop through the list at that index
    Node curr = T->list[index];
    while (curr != NULL) {
        if (strcmp(theKey, curr->key) == 0) {
            return 1;
        }
        curr=curr->next;
    }
    return 0;
}

// Look up a value based on a key
HTableItem HTableLookup(HTable T, HTableKey theKey)
{
    assert (T!=NULL);
    HTIndex index = hash(T, theKey);
    // loop through the list at that index
    Node curr = T->list[index];
    while (curr != NULL) {
        if (strcmp(theKey, curr->key) == 0) {
            return curr->val;
        }
        curr=curr->next;
    }
    fprintf(stderr,"Error: Key \"%s\" not found in HashTable\n", theKey);
    exit(1);
}

// Delete a key and associated value from the table
void HTableRemove(HTable T, HTableKey delKey)
{
    HTIndex index = hash(T, delKey);
    // loop through and remove the node when we find it
    Node * prev = &T->list[index];
    Node curr = T->list[index];
    while (curr != NULL) {
        if (strcmp(delKey, curr->key) == 0) {
            // point list around the node and free it
            *prev=curr->next;
            freeNode(curr);
            // decrement our item count
            T->items--;
            return;
        }
        prev=&curr->next;
        curr=curr->next;
    }
    // if we didn't find it, no biggie. nothing happens (should possibly error out though?)
    // may need to resize
    // TODO
    resize(T);
}

// Destroy the table and free associated memory
void HTableFree(HTable T)
{
    int i;
    for(i = 0;i < T->buckets;i++) freeBucket(T->list[i]);
    free(T);
}

static void freeBucket(Node N) {
    if (N==NULL) return;
    freeBucket(N->next);
    free(N->key);
    free(N);
}

static void freeNode(Node N) {
    if (N==NULL) return;
    free(N->key);
    free(N);
}

// just creates a new Node for us to use
static Node createNode(HTableKey newKey, HTableItem newItem)
{
    Node N = malloc(sizeof(struct _HTnode));
    N->val = newItem;
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

static void resize(HTable T)
{
}
