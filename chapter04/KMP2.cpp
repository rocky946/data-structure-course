// 改进的KMP算法
#include <stdio.h>
#include "sq_string.h"

/**
 * 计算模式串t的next数组
 * @param t
 * @param nextVal
 */
void GetNextVal(SqString t, int nextVal[]) {
    // j扫描t,k记录t[j]之前与t开头相同的字符个数
    int j, k;
    j = 0;
    k = -1;

    // 设置nextVal[0]=-1
    nextVal[0] = -1;

    // 求t所有位置的next值
    while (j < t.length - 1) {
        // k为-1或比较的字符相等时
        if (k == -1 || t.data[j] == t.data[k]) {
            // j、k依次移动到下一个字符
            j++;
            k++;

            if (t.data[j] == t.data[k]) {
                nextVal[j] = nextVal[k];
            } else {
                nextVal[j] = k;
            }
        }
        // 不相等时回退
        else {
            k = nextVal[k];
        }
    }
}

int KMPIndex(SqString s, SqString t) {
    int nextVal[MAX_SIZE], i = 0, j = 0;

    GetNextVal(t, nextVal);

    while (i < s.length && j < t.length) {
        if (j == -1 || s.data[i] == t.data[j]) {
            i++;
            j++;
        }
        // i不变，j回退
        else {
            j = nextVal[j];
        }
    }

    // 匹配成功返回子串位置
    if (j >= t.length) {
        return i - t.length;
    }
    // 匹配失败返回-1
    else {
        return -1;
    }
}

int main() {
    SqString s, t;
    char c1[] = {'a', 'a', 'a', 'b', 'a', 'a', 'a', 'a', 'b', '\0'};
    char c2[] = {'a', 'a', 'a', 'a', 'b', '\0'};
    StrAssign(s, c1);
    StrAssign(t, c2);
    printf("s:");
    DispStr(s);
    printf("t:");
    DispStr(t);
    printf("位置:%d\n", KMPIndex(s, t));
    return 0;
}
