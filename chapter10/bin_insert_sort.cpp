// 折半插入排序算法
#include "seq_list.h"
#include <stdio.h>

/**
 * 折半插入排序
 * @param R
 * @param n
 */
void BinInsertSort(RecType R[], int n) {
    int i, j, low, high, mid;
    RecType tmp;

    for (i = 1; i < n; i++) {
        // 反序时
        if (R[i].key < R[i - 1].key) {
            // 将R[i]保存到tmp中
            tmp = R[i];
            low = 0;
            high = i - 1;

            // 在R[low..high]中查找插入的位置
            while (low <= high) {
                mid = low + (high - low) / 2;
                if (tmp.key < R[mid].key) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            // 后移元素
            for (j = i - 1; j >= high + 1; j--) {
                R[j + 1] = R[j];
            }
            // 插入tmp
            R[high + 1] = tmp;
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
    BinInsertSort(R, n);
    printf("排序后:");
    DispList(R, n);

    return 0;
}