#include <stdio.h>
#include <malloc.h>
#include "ordered_array_list.h"

void OrderedListInsert(SqList *&list, ElemType e) {
    int i = 0;

    // 找到插入位置
    while (i < list->length && list->elem[i] < e) {
        i++;
    }

    // elem[i]及以后的元素后移一个位置
    for (int j = list->length; j > i; --j) {
        list->elem[j] = list->elem[j - 1];
    }
    list->elem[i] = e;
    list->length++;
}

