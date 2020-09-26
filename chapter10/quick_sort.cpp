// 快速排序算法
#include <stdio.h>
#include "seq_list.h"

int count = 0;

/**
 * 一趟划分算法
 * @param R
 * @param s
 * @param t
 * @return
 */
int partition(RecType R[], int s, int t) {
    int i = s, j = t;
    // 以R[i]为基准
    RecType tmp = R[i];

    // 从两端交替向中间扫描，直至i=j为止
    while (i < j) {
        // 从右向左扫描，找一个小于tmp.key的R[j]
        while (j > i && R[j].key >= tmp.key) {
            j--;
        }
        // 找到这样的R[j]，放入R[i]处
        R[i] = R[j];

        // 从左向右扫描，找一个大于tmp.key的R[i]
        while (i < j && R[i].key <= tmp.key) {
            i++;
        }
        // 找到这样的R[i]，放入R[j]处
        R[j] = R[i];
    }

    R[i] = tmp;
    return i;
}

/**
 * 对R[s..t]的元素进行快速排序
 * @param R
 * @param s
 * @param t
 */
void QuickSort(RecType R[], int s, int t) {
    int i;
    // 区间内至少存在两个元素
    if (s < t) {
        count++;
        i = partition(R, s, t);
        // 调试用
        DispList(R, 10);
        // 对左区间递归排序
        QuickSort(R, s, i - 1);
        // 对右区间递归排序
        QuickSort(R, i + 1, t);
    }
}

int main() {
    int n = 10;
    RecType R[MAXL];
    KeyType a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    CreateList(R, a, n);
    printf("排序前:");
    DispList(R, n);
    QuickSort(R, 0, n - 1);
    printf("排序后:");
    DispList(R, n);

    return 0;
}