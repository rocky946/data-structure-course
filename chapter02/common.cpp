#include "common.h"

/**
 * 交换元素
 * @param e1
 * @param e2
 */
void swap(ElemType &e1, ElemType &e2) {
    ElemType temp = e1;
    e1 = e2;
    e2 = temp;
}