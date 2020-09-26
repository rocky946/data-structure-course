// 自底向上的二路归并算法
#include <stdio.h>
#include "seq_list.h"
#include <malloc.h>

/**
 * 一次归并算法
 * @param R
 * @param low
 * @param mid
 * @param high
 */
void Merge(RecType *R, int low, int mid, int high) {
    RecType *R1 = nullptr;
    // i、j分别为第1、2段的下标
    int i = low, j = mid + 1, k = 0;
    // 动态分配空间
    R1 = (RecType *) malloc((high - low + 1) * sizeof(RecType));

    // 在第1段和第2段均未扫描完时循环
    while (i <= mid && j <= high) {
        // 将第1段中的元素放入R1中
        if (R[i].key <= R[j].key) {
            R1[k] = R[i];
            i++;
            k++;
        }
        // 将第2段的元素放入R1中
        else {
            R1[k] = R[j];
            j++;
            k++;
        }
    }

    // 将第1段余下的部分复制到R1
    while (i <= mid) {
        R1[k] = R[i];
        i++;
        k++;
    }

    // 将第2段余下的部分复制到R1中
    while (j <= high) {
        R1[k] = R[j];
        j++;
        k++;
    }

    // 将R1复制到R[low..high]中
    for (k = 0, i = low; i <= high; k++, i++){
        R[i] = R1[k];
    }
    // 释放R1
    free(R1);
}

/**
 * 对整个排序序列进行一趟归并
 * @param R
 * @param length
 * @param n
 */
void MergePass(RecType R[], int length, int n) {
    int i;
    // 归并length长的两个相邻子表
    for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length) {
        Merge(R, i, i + length - 1, i + 2 * length - 1);
    }
    // 余下两个子表，后者的长度小于length
    if (i + length - 1 < n - 1) {
        Merge(R, i, i + length - 1, n - 1);
    }
}

/**
 * 二路归并排序
 * @param R
 * @param n
 */
void MergeSort(RecType R[], int n) {
    int length;
    // 进行log2n取上界趟归并
    for (length = 1; length < n; length = 2 * length) {
        MergePass(R, length, n);
    }
}

int main() {
    int n = 10;
    RecType R[MAXL];
    KeyType a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    CreateList(R, a, n);
    printf("排序前:");
    DispList(R, n);
    MergeSort(R, n);
    printf("排序后:");
    DispList(R, n);

    return 0;
}
