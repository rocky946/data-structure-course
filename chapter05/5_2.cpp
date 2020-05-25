// 采用递归算法求实数数组A[0..n-1]中的最小值
#include <stdio.h>

double Min(double A[], int i) {
    double min;

    if (i == 0) {
        return A[0];
    } else {
        min = Min(A, i - 1);
        if (min > A[i]) {
            return A[i];
        } else {
            return min;
        }
    }
}

int main() {
    double A[] = {9.2, 5.5, 3.8, 7.1, 6.5};
    int n = sizeof(A) / sizeof(A[0]);
    double min = Min(A, n - 1);
    printf("min: %f\n", min);

    return 0;
}