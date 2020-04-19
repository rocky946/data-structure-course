#include <stdio.h>
#include <malloc.h>
#include "ordered_array_list.h"

ElemType MidSearch(SqList *la, SqList *lb) {
    int i = 0, j = 0, k = 0;

    while (i < la->length && j < lb->length) {
        // 当前归并的元素个数加1
        k++;
        if (la->elem[i] < lb->elem[j]) {
            // 若当前归并的元素是第n个元素，则返回
            if (k == la->length) {
                return la->elem[i];
            }
            i++;
        } else {
            // 若当前归并的元素是第n个元素，则返回
            if (k == lb->length) {
                return lb->elem[j];
            }
            j++;
        }
    }

    return 0;
}

int main() {
    // 创建la
    SqList *la = nullptr;
    ElemType a[] = {11, 13, 15, 17, 19};
    int n = sizeof(a) / sizeof(a[0]);
    CreateList(la, a, n);
    printf("la：");
    DispList(la);

    // 创建lb
    SqList *lb = nullptr;
    ElemType b[] = {2, 4, 6, 8, 20};
    n = sizeof(b) / sizeof(b[0]);
    CreateList(lb, b, n);
    printf("lb：");
    DispList(lb);

    ElemType e = MidSearch(la, lb);
    printf("e: %d\n", e);

    DestroyList(la);
    DestroyList(lb);
    return 0;
}