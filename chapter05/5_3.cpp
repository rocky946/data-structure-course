// 采用递归算法求顺序表(a1, a2, a3, ..., an)中的最大元素
#include <stdio.h>
#include "array_list.h"

/**
 * 求顺序表i..j区间的最大元素
 * @param L
 * @param i
 * @param j
 * @return
 */
ElemType Max(SqList *list, int i, int j) {
   int mid;
   ElemType max, max1, max2;

   // 递归出口，待求顺序表区间中只有一个元素
   if (i == j) {
       return list->elem[i];
   }
   // 该元素就是最大元素
   else {
       // 求中间位置
       mid = (i + j) / 2;
       // 递归调用求左子表中的最大元素max1
       max1 = Max(list, i, mid);
       // 递归调用求右子表中的最大元素max2
       max2 = Max(list, mid + 1, j);
       max = (max1 > max2) ? max1 : max2;
   }

   return max;
}

int main () {
    int a[5] = {1, 3, 1, 4, 2};
    int length = sizeof(a) / sizeof(a[0]);

    SqList *list = nullptr;

    CreateList(list, a, length);

    int max = Max(list, 0, length - 1);
    printf("max: %d\n", max);

    return 0;
}