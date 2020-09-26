// 简单选择排序算法
#include <stdio.h>
#include "seq_list.h"

/**
 * 选择排序
 * @param R 
 * @param n 
 */
void SelectSort(RecType R[], int n) {
    int i, j ,k;
    
    // 做第i趟排序
    for (i = 0; i < n - 1; i++) {
        k = i;
        // 在当前无序区R[i..n-1]中选key最小的R[key]
        for (j = i + 1; j < n; j++) {
            // k记下目前找到的最小关键字所在的位置
            if (R[j].key < R[k].key) {
                k = j;
            }
            
            // R[i]和R[j]两个元素交换
            if (k != i) {
                swap(R[i], R[k]);
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
    SelectSort(R, n);
    printf("排序后:");
    DispList(R, n);

    return 0;
}