// 顺序队列(环形队列，例3.7)
#include <stdio.h>
#include <malloc.h>
#include "sq_queue_c1.h"

void InitQueue(QuType *&queue) {
    queue = (QuType *) malloc(sizeof(QuType));
    queue->front = 0;
    queue->count = 0;
}

void DestroyQueue(QuType *&queue) {
    free(queue);
}

bool QueueEmpty(QuType *queue) {
    return queue->count == 0;
}

bool enQueue(QuType *&queue, ElemType e) {
    // 队满上溢出
    if (queue->count == MAX_SIZE) {
        return false;
    } else {
        // 队尾指针
        int rear = (queue->front + queue->count) % MAX_SIZE;
        // 队尾指针循环加1
        rear = (rear + 1) % MAX_SIZE;
        queue->data[rear] = e;
        queue->count++;
        return true;
    }
}

bool deQueue(QuType *&queue, ElemType &e) {
    // 队空下溢出
    if (queue->count == 0) {
        return false;
    } else {
        // 队头循环加1
        queue->front = (queue->front + 1) % MAX_SIZE;
        e = queue->data[queue->front];
        queue->count--;
        return true;
    }
}
