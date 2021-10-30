/**
 * as the queue datastructure contains the address of the folders
 */

typedef struct queue {
    void *data;// store any data type when accesing it typecase
    struct queue *next;
}Queue;

// linklist format
