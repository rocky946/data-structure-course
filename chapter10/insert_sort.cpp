// 直接插入排序算法
#include "seq_list.h"
#include <stdio.h>

/**
 * 直接插入排序
 * @param R
 * @param n
 */
void InsertSort(RecType R[], int n) {
    int i, j;
    RecType tmp;

    for (i = 1; i < n; i++) {
        // 反序时
        if (R[i].key < R[i - 1].key) {
            tmp = R[i];
            j = i - 1;
            // 将关键字大于R[i].key的记录后移
            do {
                R[j + 1] = R[j];
                j--;
            } while (j >= 0 && R[j].key > tmp.key);
            // 在j+1处插入R[i]
            R[j + 1] = tmp;
        }
    }
}

int main() {
    int n = 10;
    RecType R[MAXL];
    KeyType a[] = {9, 8, 7, 6, 5, 5, 3, 2, 1, 0};
    CreateList(R, a, n);
    printf("排序前:");
    DispList(R, n);
    InsertSort(R, n);
    printf("排序后:");
    DispList(R, n);

    return 0;
}