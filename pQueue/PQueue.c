// PQueue.c
// Priority Queue implementation by Nuno Das Neves
//

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"PQueue.h"

struct _PQueue {
    int nItems;
    int capacity;
    PQueueItem *items;
};

static void swap(PQueueItem a[], int i, int j);
static void heapifyDown(PQueueItem a[], int size);
static void heapifyUp(PQueueItem a[], int size);
static int getParentIndex(int i);
static int getLeftChildIndex(int i);

// Create a new PQueue with a fixed size
PQueue newPQueue(int size) {
    PQueue q = malloc(sizeof(struct _PQueue));
    assert (q != NULL);
    q->items = malloc(sizeof(PQueueItem)*size);
    assert (q->items != NULL);
    q->capacity = size;
    q->nItems = 0;
    return q;
}
// Put a new element in the pQueue
void PQueuePush(PQueue q, PQueueItem it) {
    assert (q!=NULL && q->nItems < q->capacity);
    q->items[q->nItems] = it;
    q->nItems ++;
    heapifyUp(q->items,q->nItems);
}
// Look at the top element of the pQueue
PQueueItem PQueuePeek(PQueue q) {
    assert (q != NULL && q->nItems > 0);
    return q->items[0];
}
// Pop (remove) top element of the pQueue
void PQueuePop(PQueue q) {
    assert (q != NULL && q->nItems > 0);
    swap (q->items, 0, q->nItems-1);
    q->nItems --;
    heapifyDown(q->items,q->nItems);
}
// Free all memory used by the pQueue
void PQueueFree(PQueue q) {
    assert (q != NULL);
    free (q->items);
    free (q);
}

static void heapifyUp(PQueueItem a[], int size) {
    int curr;
    for (curr = size-1;!(curr == 0 || a[getParentIndex(curr)] >= a[curr]); 
            swap(a, curr, getParentIndex(curr)));
}

static void heapifyDown(PQueueItem a[], int size) {
    int curr = 0;
    while (curr < size) {
        // get left child
        int child = getLeftChildIndex(curr);
        // if right child is bigger (and exists), select that one
        if (child+1 < size && a[child+1] > a[child]) child ++; 
        // if the selected child is smaller than curr (or doesn't exist), we're done
        if (a[curr] >= a[child] || child >= size) break;
        // swap 'em
        swap (a, curr, child);
        // and continue down throug the tree
        curr = child;
    }
    //printf ("test after\n");
    //for (curr = 0; curr < size; curr++) printf("%d ",a[curr]);
    //printf("\n");
}

static int getParentIndex(int i) {    
    return (i-1)/2;
}

static int getLeftChildIndex(int i) {
    return i*2+1;
}

static void swap(PQueueItem a[], int i, int j) {
    PQueueItem tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
