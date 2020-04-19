/**
 * 以顺序表第一个元素为分界线(基准)，将所有小于等于它的元素移到该基准的前面，将所有
 * 大于它的元素移到该基准的后面
 */
#include <stdio.h>
#include "array_list.h"
#include "common.h"

/**
 * 算法一
 * @param list
 */
void partition1(SqList *&list) {
    int i = 0;
    int j = list->length - 1;
    // 以elem[0]为基准
    ElemType pivot = list->elem[0];

    // 从区间两端交替向中间扫描，直到i=j为止
    while (i < j) {
        // 从右向左扫描，找一个小于等于pivot的元素
        while (i < j && list->elem[j] > pivot) {
            j--;
        }

        // 从左向右扫描找一个大于pivot的元素
        while (i < j && list->elem[i] <= pivot) {
            i++;
        }

        if (i < j) {
            swap(list->elem[i], list->elem[j]);
        }
    }

    // 最后将elem[0]和elem[i]进行交换
    swap(list->elem[0], list->elem[i]);
}

/**
 * 算法二
 * @param list
 */
void partition2(SqList *&list) {
    int i = 0;
    int j = list->length - 1;
    // 以elem[0]为基准
    ElemType pivot = list->elem[0];

    // 从区间两端交替向中间扫描，直到i=j为止
    while (i < j) {
        // 从右向左扫描，找一个小于等于pivot的元素
        while (i < j && list->elem[j] > pivot) {
            j--;
        }
        // 找到这样的elem[j],放入elem[i]处
        list->elem[i] = list->elem[j];

        // 从左向右扫描找一个大于pivot的元素
        while (i < j && list->elem[i] <= pivot) {
            i++;
        }
        // 找到这样的elem[i],放入elem[j]处
        list->elem[j] = list->elem[i];
    }

    // 最后将pivot放到elem[i]处
    list->elem[i] = pivot;
}

int main() {
    int a[] = {3, 8, 2, 7, 1, 5, 3, 4, 6, 0};
    int length = sizeof(a) / sizeof(a[0]);

    SqList *list = NULL;

    CreateList(list, a, length);
    DispList(list);
//    partition1(list);
    partition2(list);
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    DestroyList(list);
    printf("ListLength: %d\n", ListLength(list));
    return 0;
}