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

int main() {
    int n = 10;
    RecType R[MAXL];
    KeyType a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    CreateList(R, a, n);
    printf("排序前:");
    DispList(R, n);
    BubbleSort(R, n);
    printf("排序后:");
    DispList(R, n);

    return 0;
}