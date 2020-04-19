#ifndef CHAPTER02_TABLE_LINK_H
#define CHAPTER02_TABLE_LINK_H

// 最大列数
#define MAX_COL 10

typedef int ElemType;

// 定义数据结点
typedef struct Node1 {
    // 存放一行的数据
    ElemType data[MAX_COL];
    // 指向后继数据结点
    struct Node1 *next;
} DList;

// 定义头结点
typedef struct Node2 {
    // 行数
    int row;
    // 列数
    int col;
    // 指向第一个数据结点
    DList *next;
} HList;

/**
 * 采用交互方式建立单链表h
 * @param h
 */
void CreateTable(HList *&h);

/**
 * 销毁单链表h
 * @param h
 */
void DestroyTable(HList *&h);

/**
 * 输出单链表h
 */
void DispTable(HList *h);

/**
 * 由h1和h2连接产生结果单链表h
 * @param h1
 * @param h2
 * @param h
 */
void LinkTable(HList *h1, HList *h2, HList *&h);

#endif //CHAPTER02_TABLE_LINK_H
