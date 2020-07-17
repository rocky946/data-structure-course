// 折半(二分)查找算法
#include <stdio.h>
#include "seq_list.h"

/**
 * 折半查找
 * @param R 顺序查找表
 * @param n 元素个数
 * @param k 关键字
 * @return
 */
int BinSearch(RecType R[], int n, KeyType k) {
    int low = 0, high = n - 1, mid;

    // 当前区间存在元素时循环
    while (low <= high) {
        mid = (low + high) / 2;

        // 查找成功返回其逻辑序号mid+1
        if (k == R[mid].key) {
            return mid + 1;
        }

        // 小于mid，继续在R[low..mid-1]中查找
        if (k < R[mid].key) {
            high = mid - 1;
        }
        // 大于mid，继续在R[mid+1..high]中查找
        else {
            low = mid + 1;
        }
    }

    // 未找到时返回0(查找失败)
    return 0;
}

int main() {
    RecType R[MAXL];
    KeyType a[] = {2, 3, 10, 15, 20, 25, 28, 29, 30, 35, 40}, k = 20;
    int n = sizeof(a) / sizeof(a[0]);
    CreateList(R, a, n);
    printf("查找表disp：");
    DispList(R, n);

    printf("R中第%d个元素=%d\n", BinSearch(R, n, k), k);

    return 0;
}