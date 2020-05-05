#ifndef CHAPTER03_SQ_QUEUE_C1_H
#define CHAPTER03_SQ_QUEUE_C1_H

#define MAX_SIZE 50

typedef char ElemType;

// 顺序队环形队列类型
typedef struct {
    ElemType data[MAX_SIZE];
    // 队头
    int front;
    // 队列中元素个数
    int count;
} QuType;

/**
 * 初始化队列
 * @param queue 
 */
void InitQueue(QuType *&queue);

/**
 * 销毁队列
 * @param queue 
 */
void DestroyQueue(QuType *&queue);

/**
 * 判断队列是否为空
 * @param queue 
 * @return 
 */
bool QueueEmpty(QuType *queue);

/**
 * 进队
 * @param queue 
 * @param elemType 
 * @return 
 */
bool enQueue(QuType *&queue, ElemType e);

/**
 * 出队
 * @param queue 
 * @param e 
 * @return 
 */
bool deQueue(QuType *&queue, ElemType &e);

#endif //CHAPTER03_SQ_QUEUE_C1_H
