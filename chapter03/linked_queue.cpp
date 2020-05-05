#include <stdio.h>
#include <malloc.h>
#include "linked_queue.h"

void InitQueue(LinkQuNode *&queue) {
    queue = (LinkQuNode *) malloc(sizeof(LinkQuNode));
    queue->front = queue->rear = nullptr;
}

void DestroyQueue(LinkQuNode *&queue) {
    DataNode *pre = queue->front;
    DataNode *p = nullptr;

    if (nullptr != pre) {
        p = pre->next;
        while (nullptr != p) {
            free(pre);
            pre = p;
            p = pre->next;
        }
        free(pre);
    }

    // 释放链队结点
    free(queue);
}

bool QueueEmpty(LinkQuNode *queue) {
    return queue->rear == nullptr;
}

void enQueue(LinkQuNode *&queue, ElemType e) {
    DataNode *p = nullptr;
    // 创建数据结点
    p = (DataNode *) malloc(sizeof(DataNode));
    p->data = e;
    p->next = nullptr;

    // 若链队为空，则新结点既是队首结点又是队尾结点
    if (queue->rear == nullptr) {
        queue->front = queue->rear = p;
    }
    // 将数据结点p链到队尾，并将rear指向它
    else {
        queue->rear->next = p;
        queue->rear = p;
    }
}

bool deQueue(LinkQuNode *&queue, ElemType &e) {
    // 队空
    if (queue->rear == nullptr) {
        return false;
    }
    
    // 队首结点
    DataNode *p = queue->front;
    e = p->data;

    // 原来队列中只有一个数据结点
    if (queue->front == queue->rear) {
        queue->front = queue->rear = nullptr;
    }
    // 原来队列中有两个或两个以上的结点
    else {
        queue->front = p->next;
    }

    free(p);
    return true;
}
