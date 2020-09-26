// 堆排序算法
#include <stdio.h>
#include "seq_list.h"

/**
 * 筛选算法
 * @param R
 * @param low
 * @param high
 */
void sift(RecType R[], int low, int high) {
    int i = low, j = 2 * i;
    RecType tmp = R[i];
    while (j <= high) {
        // 若右孩子较大，把j指向右孩子
        if (j < high && R[j].key < R[j + 1].key) {
            j++;
        }

        // 若根结点小于最大孩子的关键字
        if (tmp.key < R[j].key) {
            // 将R[j]调整到双亲结点位置上
            R[i] = R[j];
            // 修改i和j的值，以便继续向下筛选
            i = j;
            j = 2 * i;
        }
        // 若根结点大于等于最大孩子关键字，筛选结束
        else break;
    }

    // 被筛选结点放入最终位置上
    R[i] = tmp;
}

/**
 * 筛选算法
 * @param R
 * @param n
 */
void HeapSort(RecType R[], int n) {
    int i;
    // 循环建立初始堆，调用sift算法n/2次
    for (i = n / 2; i >= 1; i--) {
        sift(R, i, n);
    }

    // 进行n-1趟完成堆排序，每一趟堆中元素个数减1
    for (i = n; i >= 2; i--) {
        // 将最后一个元素与R[1]交换
        swap(R[1], R[i]);
        // 对R[1..i-1]进行筛选，得到i-1个结点的堆
        sift(R, 1, i - 1);
    }
}

int main() {
    int n = 10;
    RecType R[MAXL];
    KeyType a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    CreateList1(R, a, n);
    printf("排序前:");
    DispList1(R, n);
    HeapSort(R, n);
    printf("排序后:");
    DispList1(R, n);

    return 0;
}