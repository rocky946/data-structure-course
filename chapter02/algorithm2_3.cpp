/**
 * 删除顺序表中所有值为x的元素
 */
#include <stdio.h>
#include "array_list.h"
#include "common.h"

/**
 * 算法一：重建法，基于整体建表思想
 * @param list
 * @param elemType
 */
void DeleteElem1(SqList *&list, ElemType x) {
    // k记录不等于x的元素的个数，即要插入到list中的元素个数
    int k = 0;

    for (int i = 0; i < list->length; ++i) {
        // 若当前元素不为x，将其插入到list中
        if (x != list->elem[i]) {
            list->elem[k] = list->elem[i];
            // 插入元素后元素的个数加1
            k++;
        }
    }

    // 顺序表长度为k
    list->length = k;
}

/**
 * 算法一：前移法
 * 当i指向的元素为x时k加1，否则将不为x的元素前移k个位置
 * @param list
 * @param x
 */
void DeleteElem2(SqList *&list, ElemType x) {
    // 记录等于x的元素个数，即要删除的元素个数
    int k = 0;

    for (int i = 0; i < list->length; ++i) {
        // 等于x，k++
        if (x == list->elem[i]) {
            k++;
        } else {
            // 不等于x且i前面存在等于x的元素，则将元素前移k位
            if (k != 0) {
                list->elem[i - k] = list->elem[i];
            }
        }
    }

    list->length -= k;
}

/**
 * 算法三：区间法
 * 将顺序分成两个区间,elem[0...k]为不等于x的元素区间，elem[k+1...n-1]为等于x的元素区间
 * @param list
 * @param x
 */
void DeleteElem3(SqList *&list, ElemType x) {
    // k记录要交换x元素的位置
    // 初始时k为—1表示不等于x的元素区间为空
    int k = -1;

    for (int i = 0; i < list->length; ++i) {
        // 不等于x，k加1，交换k和i位置元素;不等于x，跳过继续扫描
        if (x != list->elem[i]) {
            // 扩大不为x的区间
            k++;
            // k!=i说明i前面存在等于x的元素
            if (k != i) {
                swap(list->elem[k], list->elem[i]);
            }
        }
    }

    // 顺序表长度为k+1
    list->length = k + 1;
}

int main() {
    int a[] = {1, 2, 2, 1, 0, 2, 4, 2, 3, 1};
    int length = sizeof(a) / sizeof(a[0]);

    SqList *list = NULL;

    CreateList(list, a, length);
    DispList(list);
//    DeleteElem1(list, 2);
//    DeleteElem2(list, 2);
    DeleteElem3(list, 2);
    printf("ListLength: %d\n", ListLength(list));
    DispList(list);

    DestroyList(list);
    printf("ListLength: %d\n", ListLength(list));
    return 0;
}