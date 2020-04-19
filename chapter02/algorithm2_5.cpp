/**
 * 将顺序表所有奇数移动到偶数的前面
 */
#include <stdio.h>
#include "array_list.h"
#include "common.h"

/**
 * 算法一
 * @param list
 */
void move1(SqList *&list) {
    int i = 0;
    int j = list->length - 1;

    // 从区间两端交替向中间扫描，直到i=j为止
    while (i < j) {
        // 从右向左扫描，找奇数元素
        while (i < j && list->elem[j] % 2 == 0) {
            j--;
        }

        // 从左向右扫描找一个偶数元素
        while (i < j && list->elem[i] % 2 == 1) {
            i++;
        }

        // 若i<j，交换elem[i]和elem[j]
        if (i < j) {
            swap(list->elem[i], list->elem[j]);
        }
    }
}

/**
 * 算法二
 * @param list
 */
void move2(SqList *&list) {
    // 奇数区间
    // 初始值为-1表示奇数区间元素开始为空
    int k = -1;

    for (int i = 0; i < list->length; ++i) {
        // 若elem[i]是奇数
        if (list->elem[i] % 2 == 1) {
            // 奇数区间元素个数加1
            k++;
            // 若i不等于k，交换elem[i]和elem[k]
            if (i != k) {
                swap(list->elem[i], list->elem[k]);
            }
        }
    }
}

int main() {
    int a[] = {3, 2, 1, 9, 8, 4, 3};
    int length = sizeof(a) / sizeof(a[0]);

    SqList *list = NULL;

    CreateList(list, a, length);
    DispList(list);
//    move1(list);
    move2(list);
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    DestroyList(list);
    printf("ListLength: %d\n", ListLength(list));
    return 0;
}