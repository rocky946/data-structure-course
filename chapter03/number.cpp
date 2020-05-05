// 求解报数问题
#include <stdio.h>
#include "sq_queue.h"

void number(int n) {
    // 环形队列指针
    SqQueue *queue = nullptr;
    InitQueue(queue);

    // 构建初始序列
    for (int i = 1; i <= n; ++i) {
        enQueue(queue, i);
    }

    printf("报数出列顺序：");

    ElemType e;
    while (!QueueEmpty(queue)) {
        deQueue(queue, e);
        printf("%d ", e);

        if (!QueueEmpty(queue)) {
            deQueue(queue, e);
            // 将刚出队的元素进队
            enQueue(queue, e);
        }
    }

    printf("\n");
    DestroyQueue(queue);
}

int main() {
    int n = 8;
    printf("初始序列：");
    for (int i = 1; i <= n; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    number(n);
    return 1;
}