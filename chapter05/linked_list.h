#ifndef CHAPTER02_LINKED_LIST_H
#define CHAPTER02_LINKED_LIST_H

typedef int ElemType;

typedef struct LNode {
    // 元素
    ElemType data;
    // 指向后继结点
    struct LNode *next;
} LinkNode; // 单链表结点类型

/**
 * 整体创建单链表方法一：头插法
 * @param list 头结点
 * @param a 源数组
 * @param n 数组长度
 */
void CreateLinkedListF(LinkNode *&list, const ElemType *a, int n);

/**
 * 整体创建单链表方法二：尾插法
 * @param list 头结点
 * @param a 源数组
 * @param n 数组长度
 */
void CreateLinkedListR(LinkNode *&list, const ElemType *a, int n);

/**
 * 初始化单链表
 * @param list 头结点
 */
void InitList(LinkNode *&list);

/**
 * 销毁单链表
 * @param list 头结点
 */
void DestroyList(LinkNode *&list);

/**
 * 判断是否是空表
 * @param list 头结点
 */
bool ListEmpty(LinkNode *list);

/**
 * 计算单链表长度
 * @param list 头结点
 * @return 单链表长度
 */
int ListLength(LinkNode *list);

/**
 * 输出单链表
 * @param list 头结点
 */
void DispList(LinkNode *list);

/**
 * 查找单链表第i个元素值
 * @param list
 * @param i
 * @param e
 * @return
 */
bool GetElem(LinkNode *list, int i, ElemType &e);

/**
 * 查找第一个值等于e的结点，若找到返回逻辑序号，否则返回0
 * @param list
 * @param e
 * @return
 */
int LocateElem(LinkNode *list, ElemType &e);

/**
 * 在第i个位置插入数据元素e
 * @param list
 * @param i
 * @param e
 * @return
 */
bool ListInsert(LinkNode *&list, int i, ElemType e);

/**
 * 删除第i个数据元素，并用e返回删除元素
 * @param list
 * @param i
 * @param e
 * @return
 */
bool ListDelete(LinkNode *&list, int i, ElemType &e);

#endif //CHAPTER02_LINKED_LIST_H
