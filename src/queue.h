/**
 * as the queue datastructure contains the address of the folders
 */
typedef struct queue {
    void *data;// store any data type when accesing it typecase
    struct queue *next;
}Queue;

Queue *frontPointerQueue = NULL;
Queue *rearPointerQueue = NULL;

int isEmpty(){
    return (!frontPointerQueue && !rearPointerQueue) ? 1 : 0;
}

// linklist format
Queue *createNodesForQueue(void *address);
void *peek();
void push(void *fileAddress);
void pop();

#include "../src/queue.c"