#ifndef CHAPTER03_SQQUEUE_H
#define CHAPTER03_SQQUEUE_H

#define MAX_SIZE 50

// 方块类型
typedef struct {
    // 当前方块的行号
    int i;
    // 当前方块的列号
    int j;
    // 本路径中上一个方块在队列中的下标
    int pre;
} Box;

//typedef Box ElemType;
typedef char ElemType;

// 顺序队类型
typedef struct {
    ElemType data[MAX_SIZE];
    // 队头和队尾指针
    int front, rear;
} SqQueue;

/**
 * 初始化队列
 * @param queue 
 */
void InitQueue(SqQueue *&queue);

/**
 * 销毁队列
 * @param queue 
 */
void DestroyQueue(SqQueue *&queue);

/**
 * 判断队列是否为空
 * @param queue 
 * @return 
 */
bool QueueEmpty(SqQueue *queue);

/**
 * 进队
 * @param queue 
 * @param elemType 
 * @return 
 */
bool enQueue(SqQueue *&queue, ElemType e);

/**
 * 出队
 * @param queue 
 * @param e 
 * @return 
 */
bool deQueue(SqQueue *&queue, ElemType &e);

#endif //CHAPTER03_SQQUEUE_H
