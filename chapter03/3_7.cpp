#include <stdio.h>
#include "sq_quque_c1.h"

int main() {
    QuType *queue = nullptr;
    InitQueue(queue);

    enQueue(queue, 'a');
    enQueue(queue, 'b');
    enQueue(queue, 'c');
    enQueue(queue, 'd');

    printf("count: %d\n", queue->count);

    ElemType e;
    while (!QueueEmpty(queue)) {
        deQueue(queue, e);
        printf("%c ", e);
    }
    printf("\n");

    DestroyQueue(queue);
    
    return 0;
}
