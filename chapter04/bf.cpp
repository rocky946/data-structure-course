// BF算法
#include <stdio.h>
#include "sq_string.h"

int BF(SqString s, SqString t) {
    int i = 0, j = 0;

    // 两个串都没有扫描完时循环
    while (i < s.length && j < t.length) {
        // 当前比较的两个字符相同，比较后续字符
        if (s.data[i] == t.data[j]) {
            i++;
            j++;
        }
        // 当前比较的两个字符不相同，扫描目标串的i回退，子串从头开始
        else {
            i = i - j + 1;
            j = 0;
        }
    }

    // j越界表示t是s的子串
    // 或者j == t.length
    if (j >= t.length) {
        return i - j;
    } else {
        return -1;
    }
}

int main() {
    SqString s, t;
    char c1[] = {'a', 'b', 'a', 'b', 'c', 'a', 'b', 'c', 'a', 'c', 'b', 'a', 'b', '\0'};
    char c2[] = {'a', 'b', 'c', 'a', 'c', 'b', '\0'};
    StrAssign(s, c1);
    StrAssign(t, c2);
    printf("s:");
    DispStr(s);
    printf("t:");
    DispStr(t);
    printf("位置:%d\n", BF(s, t));
    return 0;
}