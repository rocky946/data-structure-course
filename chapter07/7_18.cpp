// 采用层次遍历方法输出从根节点到每个叶子节点的路径逆序列
#include "b_tree.h"
#include <malloc.h>
#include <stdio.h>

/*非环形队列算法(采用顺序队存储结构) start...*/
#define SQ_MAX_SIZE 100

// 非环形队列元素类型
typedef struct snode {
    // 存放当前结点指针
    BTNode *pt;
    // 存放双亲结点在队列中的位置
    int parent;
} NodeType;

typedef NodeType Sq_ElemType;

// 顺序队类型
typedef struct {
    // 存放队中元素
    Sq_ElemType data[SQ_MAX_SIZE];
    // 队头、队尾指针
    int front, rear;
} SqQueue;

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

bool enQueue(SqQueue *&queue, Sq_ElemType e) {
    // 队满上溢出
    if (queue->rear == SQ_MAX_SIZE - 1) {
        return false;
    } else {
        queue->rear++;
        queue->data[queue->rear] = e;
    }

    return true;
}

bool deQueue(SqQueue *&queue, Sq_ElemType &e) {
    // 队空下溢出
    if (queue->front == queue->rear) {
        return false;
    } else {
        queue->front++;
        e = queue->data[queue->front];
    }

    return true;
}
/*非环形队列算法(采用顺序队存储结构) end...*/

void AllPath2(BTNode *b) {
    int k;
    BTNode *p;
    // 队列元素类型
    NodeType quElem;
    // 定义非环形队列指针
    SqQueue *qu;
    // 初始化队列
    InitQueue(qu);
    // 创建根结点对应的队列元素
    quElem.pt = b;
    quElem.parent = -1;
    // 根结点指针进队
    enQueue(qu, quElem);

    // 队不为空循环
    while (!QueueEmpty(qu)) {
        // 出队元素quElem，它在队列中的下标为qu->front
        deQueue(qu, quElem);
        // 取元素quElem对应的结点p
        p = quElem.pt;
        // 结点p为叶子结点
        if (nullptr == p->lchild && nullptr == p->rchild) {
            // 输出结点p到根结点的路径的逆序列
            k = qu->front;
            while (qu->data[k].parent != -1) {
                printf("%c->", qu->data[k].pt->data);
                k = qu->data[k].parent;
            }
            printf("%c\n", qu->data[k].pt->data);
        }

        // 结点p有左孩子
        if (nullptr != p->lchild) {
            // 创建结点p的左孩子对应的队列元素
            quElem.pt = p->lchild;
            quElem.parent = qu->front;
            enQueue(qu, quElem);
        }
        // 结点p有右孩子
        if (nullptr != p->rchild) {
            // 创建结点p的左孩子对应的队列元素
            quElem.pt = p->rchild;
            quElem.parent = qu->front;
            enQueue(qu, quElem);
        }
    }

    DestroyQueue(qu);
}

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    printf("disp: ");
    DisplayBTree(b);

    printf("所有叶子结点到根节点的序列:\n");
    AllPath2(b);

    DestroyBTree(b);

    return 0;
}