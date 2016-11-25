// List ADT for stacking, queueing etc

#include<stdlib.h>
#include<stdio.h>
#include "List.h"
#include <assert.h>

typedef struct _node * Node;

struct _node {
    ListItem data; // this is just a void pointer
    List next;
};

struct _list {
    u_int32_t size;
    Node head;
    Node tail;
};

// create new list
List ListNew()
{
    L = malloc (sizeof(struct _list));
    assert(L != NULL);
    L->size = 0;
    L->head = NULL;
    L->tail = NULL;
    return l;
}

static Node newNode(ListItem it) {
    N = malloc (sizeof(struct _node));
    assert (N != NULL);
    N->data = it;
    N->next = NULL;
    return N;
}

// push to the front
void ListShift(List L,ListItem it)
{
    assert(L != NULL);
    n = newNode(it);
    n->next = L->head;
    L->head = n;
    L->size ++;
    if (L->size == 1) L->tail = L->head;
}

// remove from front
void ListUnShift(List L, (void)f(ListItem))
{
    assert(L != NULL);
    if (L->size == 0) return;
    // free the data
    f(L->head->data);
    Node tmp = L->head;
    L->head = L->head->next;
    free(tmp);
    L->size--;
    if (L->size == 0) L->tail == NULL;
}

// append to the end
void ListPush(List L,ListItem it)
{
    assert(L != NULL);
    n = newNode(it);
    if (L->size > 0) L->tail->next = n;
    else {
        L->head = n;
    }
    L->tail = n;
    L->size ++;
}

// returns top item
ListItem ListTop(List L)
{
    assert(L != NULL);
    if (L->size > 0) return L->head->data;
    return NULL;   
}

// returns bottom item
ListItem ListBottom(List L)
{
    assert(L != NULL);
    if (L->size > 0) return L->tail->data;
    return NULL;   
}

// frees the list items; takes a function that frees the list item (can just be free() for non-structs)
void ListDestroy(List L, (void)f(ListItem))
{
    assert (L != NULL);
    Node curr,tmp;
    for (curr = L->head; curr != NULL; curr = tmp) {
        f(curr->data);
        tmp = curr->next;
        free(curr);
    }
    free (L);
}

