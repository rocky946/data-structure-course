// 例2.14(p66)
// 假设有两个有序表LA和LB，设计一个算法，将它们合并成一个有序表LC(假设每个有序表中和两个
// 有序表间不存在重复元素)，要求不破坏原有表LA和LB
// 算法一：采用顺序表存放有序表时的二路归并算法
#include <stdio.h>
#include <malloc.h>
#include "ordered_array_list.h"

void UnionList(SqList *LA, SqList *LB, SqList *&LC) {
    LC = (SqList *) malloc(sizeof(SqList));
    // i、j分别为扫描LA、LB元素下标
    // k：LC中元素的个数
    int i = 0, j = 0, k = 0;

    while (i < LA->length && j < LB->length) {
        if (LA->elem[i] < LB->elem[j]) {
            LC->elem[k] = LA->elem[i];
            i++;
            k++;
        } else {
            LC->elem[k] = LB->elem[j];
            j++;
            k++;
        }
    }

    // 将LA剩下的元素复制到LC中
    while (i < LA->length) {
        LC->elem[k] = LA->elem[i];
        i++;
        k++;
    }

    // 将LB剩下的元素复制到LC中
    while (j < LB->length) {
        LC->elem[k] = LB->elem[j];
        j++;
        k++;
    }

    LC->length = k;
}

int main() {
    // 创建LA
    SqList *LA = nullptr;
    ElemType a[] = {1, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    CreateList(LA, a, n);
    printf("LA：");
    DispList(LA);

    // 创建LB
    SqList *LB = nullptr;
    ElemType b[] = {2, 4, 8, 10};
    n = sizeof(b) / sizeof(b[0]);
    CreateList(LB, b, n);
    printf("LB：");
    DispList(LB);

    // 创建LC
    SqList *LC = nullptr;
    UnionList(LA, LB, LC);
    printf("LC：");
    DispList(LC);

    printf("len:%d", LC->length);

    DestroyList(LA);
    DestroyList(LB);
    DestroyList(LC);

    return 0;
}
