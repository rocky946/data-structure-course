// 【例3.8】 采用一个不带头结点只有一个尾结点指针rear的循环单链表存储队列，设计
// 设计队列的初始化、进队和出队算法

#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node *next;
} LinkNode;

 /**
  * 初始化队列
  * @param rear 尾指针
  */
void InitQueue(LinkNode *&rear) {
     rear = nullptr;
}

/**
 * 判断队列是否为空
 * @param rear
 * @return
 */
bool QueueEmpty(LinkNode *rear) {
    return rear == nullptr;
}

/**
 * 进队
 * @param rear
 * @param e
 */
void enQueue(LinkNode *&rear, ElemType e) {
    // 创建新结点p
    LinkNode *p = nullptr;
    p = (LinkNode *) malloc(sizeof(LinkNode));
    p->data = e;

    // 原链队为空
    if (rear == nullptr) {
        // 改为循环链表
        p->next = p;
        // rear指向新结点
        rear = p;
    }
    // 原链队不为空
    else {
        // 将p插入到rear之后
        p->next = rear->next;
        rear->next = p;
        rear = p;
    }
}

/**
 * 出队
 * @param rear
 * @param e
 * @return
 */
bool deQueue(LinkNode *&rear, ElemType &e) {
    // 队空
    if (rear == nullptr) {
        return false;
    }

    // 原队列只有一个结点
    if (rear->next == rear) {
        e = rear->data;
        free(rear);
        rear = nullptr;
    }
    // 原队列中有两个或两个以上的结点
    else {
        LinkNode *p = rear->next;
        e = p->data;
        rear->next = p->next;
        free(p);
    }

    return true;
}

int main() {
    LinkNode *rear = nullptr;

    InitQueue(rear);

    enQueue(rear, 1);
    enQueue(rear, 2);
    enQueue(rear, 3);
    enQueue(rear, 4);
    enQueue(rear, 5);

    printf("empty: %d\n", QueueEmpty(rear));

    ElemType e;
    while (!QueueEmpty(rear)) {
        deQueue(rear, e);
        printf("%d ", e);
    }

    printf("\n");

    printf("empty: %d\n", QueueEmpty(rear));

    return 0;
}