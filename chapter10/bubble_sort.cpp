// 冒泡排序算法
#include <stdio.h>
#include "seq_list.h"

/**
 * 冒泡排序
 * @param R
 * @param n
 */
void BubbleSort(RecType R[], int n) {
    int i, j;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (R[j].key > R[j + 1].key) {
                swap(R[j], R[j + 1]);
            }
        }
    }
}

/**
 * 冒泡排序（从后往前冒泡）
 * @param R
 * @param n
 */
void BubbleSort1(RecType R[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        // 将R[i]元素归位
        for (j = n - 1; j > i; j--) {
            // 相邻两个元素反序时交换
            if (R[j].key < R[j - 1].key) {
                swap(R[j], R[j - 1]);
            }
        }
        DispList(R, n);
    }
}

int main() {
    int n = 10;
    RecType R[MAXL];
    KeyType a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    CreateList(R, a, n);
    printf("排序前:");
    DispList(R, n);
    BubbleSort1(R, n);
    printf("排序后:");
    DispList(R, n);

    return 0;
}