#ifndef CHAPTER02_ARRAY_LIST_H
#define CHAPTER02_ARRAY_LIST_H

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType elem[MaxSize];
    int length;
} SqList;

/**
 * 由数组a[]创建顺序表
 * @param list 顺序表
 * @param a 源数组
 * @param n
 */
void CreateList(SqList *&list, const ElemType *a, int n);

/**
 * 初始化顺序表
 * @param list
 */
void InitList(SqList *&list);

/**
 * 销毁顺序表
 * @param list
 */
void DestroyList(SqList *&list);

/**
 * 判断是否是空表
 * @param list
 * @return
 */
bool ListEmpty(const SqList *list);

/**
 * 计算顺序表的长度
 * @param list
 * @return
 */
int ListLength(const SqList *list);

/**
 * 输出顺序表
 * @param list
 */
void DispList(const SqList *list);

/**
 * 用e返回顺序表第i(1<=i<=n)个元素的值
 * @param list
 * @param i
 * @param e
 * @return
 */
bool GetElem(const SqList *list, int i, ElemType &e);

/**
 * 查找第一个e的逻辑序号，若找到返回一个大于0的值
 * @param list
 * @param e
 * @return
 */
int LocateElem(const SqList *list, ElemType e);

/**
 * 在顺序表的第i(1<=i<=n+1)个位置上插入新元素e
 * @param list
 * @param i
 * @param e
 * @return
 */
bool ListInsert(SqList *&list, int i, ElemType e);

/**
 * 删除顺序表第i(1<=i<=n)个元素，并用e返回删除的元素
 * @param list
 * @param i
 * @param e
 * @return
 */
bool ListDelete(SqList *&list, int i, ElemType &e);

#endif //CHAPTER02_ARRAY_LIST_H
