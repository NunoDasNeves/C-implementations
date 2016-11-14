// PQueue.h
// Priority Queue interface by Nuno Das Neves
//

typedef u_int32_t PQueueItem;

#ifndef PQUEUE_H
#define PQUEUE_H
// ADT pointer
typedef struct _PQueue *PQueue;
// Create a new PQueue with a fixed size
PQueue newPQueue(int size);
// Put a new element in the pQueue
void PQueuePush(PQueue q, PQueueItem it);
// Look at the top element of the pQueue
PQueueItem PQueuePeek(PQueue);
// Pop (remove) top element of the pQueue
void PQueuePop(PQueue);
// Free all memory used by the pQueue
void PQueueFree(PQueue);
#endif
