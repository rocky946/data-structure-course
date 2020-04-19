#include <stdio.h>
#include <malloc.h>
#include "array_list.h"

void CreateList(SqList *&list, const ElemType *a, int n) {
    // 分配线性表空间
    list = (SqList *) malloc(sizeof(SqList));

    for (int i = 0; i < n; ++i) {
        list->elem[i] = a[i];
    }

    list->length = n;
}

void InitList(SqList *&list) {
    // 分配顺序表存储空间，并将length设置为0
    list = (SqList *) malloc(sizeof(SqList));
    list->length = 0;
}

void DestroyList(SqList *&list) {
    // 释放顺序表存储空间
    list->length = 0;
    free(list);
}

bool ListEmpty(const SqList *list) {
    return list->length == 0;
}

int ListLength(const SqList *list) {
    return list->length;
}

void DispList(const SqList *list) {
    for (int i = 0; i < list->length; ++i) {
        printf("%d ", list->elem[i]);
    }
    printf("\n");
}

bool GetElem(const SqList *list, int i, ElemType &e) {
    if (i < 1 || i > list->length) {
        printf("参数i非法,i = %d\n", i);
        return false;
    }

    e = list->elem[i - 1];

    return true;
}

int LocateElem(const SqList *list, ElemType e) {
    int index = 0;

    for (int i = 0; i < list->length; ++i) {
        if (e == list->elem[i]) {
            break;
        }
        index++;
    }

    return index + 1;
}

bool ListInsert(SqList *&list, int i, ElemType e) {
    if (i < 1 || i > list->length + 1) {
        printf("参数i非法,i = %d\n", i);
        return false;
    }

    // 将逻辑序号转为物理序号
    i--;

    // 将elem[i]及后面的元素后移一个位置
    for (int j = list->length; j > i; j--) {
        list->elem[j] = list->elem[j - 1];
    }

    // 插入元素e
    list->elem[i] = e;
    // 长度加1
    list->length++;

    return true;
}

bool ListDelete(SqList *&list, int i, ElemType &e) {
    if (i < 1 || i > list->length) {
        printf("参数i非法,i = %d\n", i);
        return false;
    }

    // 将逻辑序号转为物理序号
    i--;
    e = list->elem[i];

    // 将elem[i]以后的元素前移一个位置
    for (int j = i; j < list->length; ++j) {
        list->elem[j] = list->elem[j + 1];
    }

    // 长度减1
    list->length--;

    return true;
}


