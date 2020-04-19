#ifndef CHAPTER02_DLINKED_LIST_H
#define CHAPTER02_DLINKED_LIST_H

typedef int ElemType;

typedef struct DLNode {
    // 元素
    ElemType data;
    // 指向前驱结点
    struct DLNode *prior;
    // 指向后继结点
    struct DLNode *next;
} DLinkNode; // 双链表结点类型

/**
 * 整体创建双链表方法一：头插法
 * @param list 头结点
 * @param a 源数组
 * @param n 数组长度
 */
void CreateDLinkedListF(DLinkNode *&list, const ElemType *a, int n);

/**
 * 整体创建双链表方法二：尾插法
 * @param list 头结点
 * @param a 源数组
 * @param n 数组长度
 */
void CreateDLinkedListR(DLinkNode *&list, const ElemType *a, int n);

/**
 * 初始化双链表
 * @param list 头结点
 */
void InitList(DLinkNode *&list);

/**
 * 销毁双链表
 * @param list 头结点
 */
void DestroyList(DLinkNode *&list);

/**
 * 判断是否是空表
 * @param list 头结点
 */
bool ListEmpty(DLinkNode *list);

/**
 * 计算双链表长度
 * @param list 头结点
 * @return 双链表长度
 */
int ListLength(DLinkNode *list);

/**
 * 输出双链表
 * @param list 头结点
 */
void DispList(DLinkNode *list);

/**
 * 查找双链表第i个元素值
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


#endif //CHAPTER02_DLINKED_LIST_H

