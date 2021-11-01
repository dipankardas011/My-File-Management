
void push(void *fileAddress) {
    if (isEmpty()) {
        frontPointerQueue = rearPointerQueue = createNodesForQueue(fileAddress);
        return ;
    }
    rearPointerQueue->next = createNodesForQueue(fileAddress);
    rearPointerQueue = rearPointerQueue->next;
}

void pop() {
    if (isEmpty()) {
        return ;
    }
    Queue *t = NULL;
    if (frontPointerQueue == rearPointerQueue) {
        t = frontPointerQueue;
        free(frontPointerQueue);
        frontPointerQueue = rearPointerQueue = NULL;
    } else {
        t = frontPointerQueue;
        frontPointerQueue = frontPointerQueue->next;
        free(t);
    }
}

void *peek() {
    if(isEmpty()) {
        return NULL;
    }
    return (frontPointerQueue->data);
}

Queue *createNodesForQueue(void *address) {
    Queue *t = (Queue *)malloc(sizeof(Queue));
    t->data = address;
    t->next = NULL;
    return t;
}

void display() {
    if (!isEmpty()) {
        printf("[");
        Queue *f = frontPointerQueue;
        do {
            // printf("%s",((Folders*)f->data)->folderName);
            f = f->next;
        }while (f != NULL && printf(", "));
        printf("]\n");
    }else
    printf("[]\n");
}