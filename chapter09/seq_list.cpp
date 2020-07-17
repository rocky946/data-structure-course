// 顺序表基本运算算法
#include <stdio.h>
#include "seq_list.h"

void CreateList(RecType R[], KeyType keys[], int n) {
    for (int i = 0; i < n; ++i) {
        R[i].key = keys[i];
    }
}

void DispList(RecType R[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", R[i].key);
    }
    printf("\n");
}

