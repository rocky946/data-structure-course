#include <stdio.h>
#include "tuples.h"

int main() {
    TSMatrix t, tb;
    int x, y = 10;
    int i, j;

    int A[6][7] = {
            {0, 0, 1, 0, 0, 0, 0},
            {0, 2, 0, 0, 0, 0, 0},
            {3, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 5, 0, 0, 0},
            {0, 0, 0, 0, 6, 0, 0},
            {0, 0, 0, 0, 0, 7, 4}};

    CreateMat(t, A);
    printf("disp t:\n");
    DispMat(t);

    i = 2;
    j = 5;
    if (Assign(t, x, i, j))
        printf("Assign,x=%d\n", x);
    else  //调用时返回false
        printf("Assign参数错误\n");

    Value(t, y, i, j);
    if (Value(t, y, i, 5))
        printf("Value,y=%d\n", y);
    else  //调用时返回false
        printf("Value参数错误\n");

    printf("dist t:\n");
    DispMat(t);

    TranTat(t, tb);
    printf("disp tb:\n");
    DispMat(tb);

    return 0;
}