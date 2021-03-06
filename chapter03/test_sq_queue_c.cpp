#include <stdio.h>
#include "sq_queue.h"

int main() {
    SqQueue *queue = nullptr;
    InitQueue(queue);

    enQueue(queue, 'a');
    enQueue(queue, 'b');
    enQueue(queue, 'c');
    enQueue(queue, 'd');

    ElemType e;
    while (!QueueEmpty(queue)) {
        deQueue(queue, e);
        printf("%c ", e);
    }
    printf("\n");

    DestroyQueue(queue);

    return 0;
}