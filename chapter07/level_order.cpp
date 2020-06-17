// 二叉树层次遍历算法
#include "b_tree.h"
#include <malloc.h>
#include <stdio.h>

/*环形队列算法(采用顺序队存储结构) start...*/
#define SQ_MAX_SIZE 100

typedef BTNode *Sq_ElemType;

// 顺序队类型
typedef struct {
    // 存放队中元素
    Sq_ElemType data[SQ_MAX_SIZE];
    // 队头、队尾指针
    int front, rear;
} SqQueue;

void InitQueue(SqQueue *&queue) {
    queue = (SqQueue *) malloc(sizeof(SqQueue));
    queue->front = queue->rear = 0;
}

void DestroyQueue(SqQueue *&queue) {
    free(queue);
}

bool QueueEmpty(SqQueue *queue) {
    return queue->front == queue->rear;
}

bool enQueue(SqQueue *&queue, Sq_ElemType e) {
    // 队满上溢出
    if ((queue->rear + 1) % SQ_MAX_SIZE == queue->front) {
        return false;
    } else {
        queue->rear = (queue->rear + 1) % SQ_MAX_SIZE;
        queue->data[queue->rear] = e;
    }

    return true;
}

bool deQueue(SqQueue *&queue, Sq_ElemType &e) {
    // 队空下溢出
    if (queue->front == queue->rear) {
        return false;
    } else {
        queue->front = (queue->front + 1) % SQ_MAX_SIZE;
        e = queue->data[queue->front];
    }

    return true;
}
/*环形队列算法(采用顺序队存储结构) end...*/

/**
 * 层次遍历算法
 * @param p
 */
void LevelOrder(BTNode *b) {
    BTNode *p;
    // 定义环形队列指针
    SqQueue *qu;
    // 初始化队列
    InitQueue(qu);
    // 根结点指针进队
    enQueue(qu, b);

    // 队不为空循环
    while (!QueueEmpty(qu)) {
        // 出队结点p
        deQueue(qu, p);
        // 访问结点p
        printf("%c ", p->data);
        // 有左孩子时将其进队
        if (nullptr != p->lchild) {
            enQueue(qu, p->lchild);
        }
        // 有右孩子时将其进队
        if (nullptr != p->rchild) {
            enQueue(qu, p->rchild);
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

    printf("\n层次遍历：\n");
    LevelOrder(b);

    DestroyBTree(b);

    return 0;
}