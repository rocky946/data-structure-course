#ifndef CHAPTER02_CDLINKED_LIST_H
#define CHAPTER02_CDLINKED_LIST_H

typedef int ElemType;

typedef struct DLNode {
    // 元素
    ElemType data;
    // 指向前驱结点
    struct DLNode *prior;
    // 指向后继结点
    struct DLNode *next;
} DLinkNode; // 循环双链表结点类型

/**
 * 整体创建循环双链表方法一：头插法
 * @param list 头结点
 * @param a 源数组
 * @param n 数组长度
 */
void CreateCDLinkedListF(DLinkNode *&list, const ElemType *a, int n);

/**
 * 整体创建循环双链表方法二：尾插法
 * @param list 头结点
 * @param a 源数组
 * @param n 数组长度
 */
void CreateCDLinkedListR(DLinkNode *&list, const ElemType *a, int n);

/**
 * 初始化循环双链表
 * @param list 头结点
 */
void InitList(DLinkNode *&list);

/**
 * 销毁循环双链表
 * @param list 头结点
 */
void DestroyList(DLinkNode *&list);

/**
 * 判断是否是空表
 * @param list 头结点
 */
bool ListEmpty(DLinkNode *list);

/**
 * 计算循环双链表长度
 * @param list 头结点
 * @return 循环双链表长度
 */
int ListLength(DLinkNode *list);

/**
 * 输出循环双链表
 * @param list 头结点
 */
void DispList(DLinkNode *list);

/**
 * 查找循环双链表第i个元素值
 * @param list
 * @param i
 * @param e
 * @return
 */
bool GetElem(DLinkNode *list, int i, ElemType &e);

/**
 * 查找第一个值等于e的结点，若找到返回逻辑序号，否则返回0
 * @param list
 * @param e
 * @return
 */
int LocateElem(DLinkNode *list, ElemType &e);

/**
 * 在第i个位置插入数据元素e
 * @param list
 * @param i
 * @param e
 * @return
 */
bool ListInsert(DLinkNode *&list, int i, ElemType e);

/**
 * 删除第i个数据元素，并用e返回删除元素
 * @param list
 * @param i
 * @param e
 * @return
 */
bool ListDelete(DLinkNode *&list, int i, ElemType &e);

#endif //CHAPTER02_CDLINKED_LIST_H
