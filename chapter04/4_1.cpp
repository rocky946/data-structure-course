#include <stdio.h>
#include "sq_string.h"

/**
 * 比较串s和t的大小
 * @param s
 * @param t
 * @return
 */
int StrCmp(SqString s, SqString t) {
    // s,t共同长度
    int comLen = StrLength(s) <= StrLength(t) ? StrLength(s) : StrLength(t);

    // 在共同长度内逐个字符比较
    for (int i = 0; i < comLen; ++i) {
        if (s.data[i] > t.data[i]) {
            return 1;
        } else if (s.data[i] < t.data[i]) {
            return -1;
        }
    }

    if (s.length == t.length) {
        return 0;
    } else if (s.length > t.length) {
        return 1;
    } else {
        return -1;
    }
}

int main() {
    char s1[] = {'a', 'b', 'c', 'd', '\0'};
    char t1[] = {'a', 'b', 'c', '\0'};

    SqString s;
    StrAssign(s, s1);
    SqString t;
    StrAssign(t, t1);

    int ret = StrCmp(s, t);
    printf("ret : %d\n", ret);
}