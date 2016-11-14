// testPQueue.c
// Priority Queue unit tests by Nuno Das Neves
//

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"PQueue.h"

int main() {
    
    PQueue q = newPQueue(5);
    
    PQueuePush(q, 3);
    assert(PQueuePeek(q)==3); 
    PQueuePop(q);

    PQueuePush(q, 3);
    assert(PQueuePeek(q)==3);
    PQueuePush(q, 100);
    assert(PQueuePeek(q)==100);
    PQueuePush(q, 1);
    assert(PQueuePeek(q)==100);
    PQueuePush(q, 66);
    assert(PQueuePeek(q)==100);
    PQueuePush(q, 100);
    assert(PQueuePeek(q)==100);
    PQueuePop(q);
    assert(PQueuePeek(q)==100);
    PQueuePop(q);
    assert(PQueuePeek(q)==66);
    PQueuePop(q);
    assert(PQueuePeek(q)==3);
    PQueuePop(q);
    assert(PQueuePeek(q)==1);
    PQueuePop(q);

    

    // Free all memory used by the pQueue
    PQueueFree(q);

    return EXIT_SUCCESS;
}

