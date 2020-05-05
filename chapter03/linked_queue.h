#ifndef CHAPTER03_LINKED_QUEUE_H
#define CHAPTER03_LINKED_QUEUE_H

typedef char ElemType;

// 链队数据结点类型
typedef struct QNode {
    ElemType data;
    // 下一结点指针
    struct QNode *next;
} DataNode;

// 链队结点类型
typedef struct {
    // 指向队首结点
    DataNode *front;
    DataNode *rear;
} LinkQuNode;

/**
 * 初始化链队
 * @param queue
 */
void InitQueue(LinkQuNode *&queue);

/**
 * 销毁链队
 */
void DestroyQueue(LinkQuNode *&queue);

/**
 * 判断队列是否为空
 */
bool QueueEmpty(LinkQuNode *queue);

/**
 * 元素e进队
 * @param queue
 * @param e
 */
void enQueue(LinkQuNode *&queue, ElemType e);

/**
 * 出队
 * @param queue
 * @param e
 * @return
 */
bool deQueue(LinkQuNode *&queue, ElemType &e);

#endif //CHAPTER03_LINKED_QUEUE_H
