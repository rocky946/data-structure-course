#include <stdio.h>
#include "sq_queue.h"

/**
 * 从队尾删除
 * @param queue
 * @param e
 * @return
 */
bool deQueue1(SqQueue *&queue, ElemType &e) {
    // 队空
    if (queue->front == queue->rear) {
        return false;
    }

    e = queue->data[queue->rear];
    // 修改队尾指针
    queue->rear = (queue->rear - 1 + MAX_SIZE) % MAX_SIZE;
    return true;
}

/**
 * 从队头插入
 * @param queue
 * @param e
 * @return
 */
bool enQueue1(SqQueue *&queue, ElemType e) {
    // 队满
    if ((queue->rear + 1) % MAX_SIZE == queue->front) {
        return false;
    }

    queue->data[queue->front] = e;
    // 修改队头指针
    queue->front = (queue->front - 1 + MAX_SIZE) % MAX_SIZE;
    return true;
}

int main() {
    SqQueue *queue = nullptr;
    InitQueue(queue);

    // 从队尾插入a, b
    enQueue(queue, 'a');
    enQueue(queue, 'b');

    // 从队头插入c, d
    enQueue1(queue, 'c');
    enQueue1(queue, 'd');

    // 从队尾插入e
    enQueue(queue, 'e');

    ElemType e;
    printf("从队头出队两个元素：");
    for (int i = 0; i < 2; ++i) {
        deQueue(queue, e);
        printf("%c ", e);
    }

    printf("\n从队尾出队其他元素: ");
    while (!QueueEmpty(queue)) {
        deQueue1(queue, e);
        printf("%c ", e);
    }

    printf("\n");

    DestroyQueue(queue);
    return 0;
}