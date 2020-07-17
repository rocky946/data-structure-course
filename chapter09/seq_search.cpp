// 顺序查找算法
#include <stdio.h>
#include "seq_list.h"

/**
 * 顺序查找算法1
 * @param n 元素个数
 * @param k 关键字
 * @return 元素的逻辑序号
 */
int SeqSearch1(RecType R[], int n, KeyType k) {
    int i = 0;

    // 从表头往后找
    while (i < n && R[i].key != k) {
        i++;
    }

    // 未找到返回0
    if (i == n) {
        return 0;
    }
    // 找到返回逻辑序号i+1
    else {
        return i + 1;
    }
}

/**
 * 顺序查找算法2(增加一个哨兵)
 * @param n 元素个数
 * @param k 关键字
 * @return 元素的逻辑序号
 */
int SeqSearch2(RecType R[], int n, KeyType k) {
    int i = 0;

    // 表尾增加一个哨兵
    R[n].key = k;
    // 从表头往后找
    while (R[i].key != k) {
        i++;
    }

    // 未找到返回0
    if (i == n) {
        return 0;
    }
     // 找到返回逻辑序号i+1
    else {
        return i + 1;
    }
}

int main() {
    RecType R[MAXL];
    KeyType a[] = {2, 3, 1, 8, 5, 4, 9, 0, 7, 6}, k = 9;
    int n = sizeof(a) / sizeof(a[0]);
    CreateList(R, a, n);
    printf("查找表disp：");
    DispList(R, n);

    printf("R第%d个元素=%d\n", SeqSearch1(R, n, k), k);

    return 0;
}