// 改进的冒泡排序算法
#include <stdio.h>
#include "seq_list.h"

/**
 * 改进的冒泡排序
 * @param R
 * @param n
 */
void BubbleSort1(RecType R[], int n) {
    int i, j;
    bool exchange;

    for (i = n - 1; i > 0; i--) {
        // 一趟排序前exchange置为假
        exchange = false;
        for (j = 0; j < i; j++) {
            if (R[j].key > R[j + 1].key) {
                swap(R[j], R[j + 1]);
                // 一旦有交换，exchange置为真
                exchange = true;
            }
        }

        // 本趟没有发生交换，中途结束算法
        if (!exchange) {
            return;
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
    BubbleSort1(R, n);
    printf("排序后:");
    DispList(R, n);

    return 0;
}