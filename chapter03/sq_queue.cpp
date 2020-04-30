// 顺序队列(非环形队列)
#include <stdio.h>
#include <malloc.h>
#include "sq_queue.h"

void InitQueue(SqQueue *&queue) {
    queue = (SqQueue *) malloc(sizeof(SqQueue));
    queue->front = queue->rear = -1;
}

void DestroyQueue(SqQueue *&queue) {
    free(queue);
}

bool QueueEmpty(SqQueue *queue) {
    return queue->front == queue->rear;
}

bool enQueue(SqQueue *&queue, ElemType e) {
    // 队满上溢出
    if (queue->rear == MAX_SIZE - 1) {
        return false;
    } else {
        queue->rear++;
        queue->data[queue->rear] = e;
    }
    
    return true;
}

bool deQueue(SqQueue *&queue, ElemType &e) {
    // 队空下溢出
    if (queue->front == queue->rear) {
        return false;
    } else {
        queue->front++;
        e = queue->data[queue->front];
    }
    
    return true;
}
