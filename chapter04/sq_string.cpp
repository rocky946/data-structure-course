#include <stdio.h>
#include "sq_string.h"

void StrAssign(SqString &s, char *cstr) {
    int i;
    for (i = 0; cstr[i] != '\0'; i++) {
        s.data[i] = cstr[i];
    }
    // 设置串s的长度
    s.length = i;
}

void DestroyStr(SqString &s) {

}

void StrCopy(SqString &s, SqString t) {
    for (int i = 0; i < t.length; ++i) {
        s.data[i] = t.data[i];
    }
    s.length = t.length;
}

bool StrEqual(SqString s, SqString t) {
    bool same = true;

    // 长度不相等时返回false
    if (s.length != t.length) {
        same = false;
    } else {
        for (int i = 0; i < s.length; ++i) {
            // 有一个对应字符不相等时返回false
            if (s.data[i] != t.data[i]) {
                same = false;
                break;
            }
        }
    }

    return same;
}

int StrLength(SqString s) {
    return s.length;
}

SqString Concat(SqString s, SqString t) {
    // 定义结果串
    SqString str;

    int i;
    // 将s.data[0..s.length-1]复制到str
    for (i = 0; i < s.length; i++) {
        str.data[i] = s.data[i];
    }

    // 将t.data[0..t.length-1]复制到str
    for (i = 0; i < t.length; i++) {
        str.data[s.length + i] = t.data[i];
    }

    str.length = s.length + t.length;

    return str;
}

SqString SubStr(SqString s, int i, int j) {
    // 定义结果串
    SqString str;
    // 初始化str为空串
    str.length = 0;
    // 参数不合法返回空串
    if (i <= 0 || i > s.length || j < 0 || i + j - 1 > s.length) {
        return str;
    }

    // 将s.data[i-1..i+j-2]复制到str
    for (int k = i - 1; k < i + j - 1; ++k) {
        str.data[k - i + 1] = s.data[k];
    }
    str.length = j;
    return str;
}

SqString InsString(SqString s1, int i, SqString s2) {
    // 定义结果串
    SqString str;
    // 初始化str为空串
    str.length = 0;
    // 参数不合法返回空串
    if (i <= 0 || i > s1.length + 1) {
        return str;
    }

    int j;
    // 将s1.data[0..i-2]复制到str
    for (j = 0; j < i - 1; ++j) {
        str.data[j] = s1.data[j];
    }

    // 将s2.data[0..s2.length-1]复制到str
    for (j = 0; j < s2.length; ++j) {
        str.data[i + j - 1] = s2.data[j];
    }

    // 将s1.data[i-1..s1.length-1]复制到str
    for (j = i - 1; j < s1.length; ++j) {
        str.data[s2.length + j] = s1.data[j];
    }

    str.length = s1.length + s2.length;

    return str;
}

SqString DelString(SqString s, int i, int j) {
    // 定义结果串
    SqString str;
    // 初始化str为空串
    str.length = 0;
    // 参数不合法返回空串
    if (i <= 0 || i > s.length || j < 0 || i + j - 1 > s.length) {
        return str;
    }

    int k;
    // 将s.data[0..i-2]复制到str
    for (k = 0; k < i - 1; ++k) {
        str.data[k] = s.data[k];
    }

    // 将s.data[i+j-1..s.length-1]复制到str
    for (k = i + j -1; k < s.length; ++k) {
        str.data[k - j] = s.data[k];
    }
    str.length = s.length - j;

    return str;
}

SqString RepStr(SqString s, int i, int j, SqString t) {
    // 定义结果串
    SqString str;
    // 初始化str为空串
    str.length = 0;
    // 参数不合法返回空串
    if (i <= 0 || i > s.length || j < 0 || i + j - 1 > s.length) {
        return str;
    }

    int k;
    // 将s.data[0..i-2]复制到str
    for (k = 0; k < i - 1; ++k) {
        str.data[k] = s.data[k];
    }

    // 将t.data[0..t.length-1]复制到str
    for (k = 0; k < t.length; ++k) {
        str.data[i - 1 + k] = t.data[k];
    }

    // 将s.data[i+j-1..s.length-1]复制到str
    for (k = i + j -1; k < s.length; ++k) {
        str.data[t.length + k - j] = s.data[k];
    }

    str.length = s.length - j + t.length;

    return str;
}

void DispStr(SqString s) {
    if (s.length > 0) {
        for (int i = 0; i < s.length; ++i) {
            printf("%c", s.data[i]);
        }
        printf("\n");
    }
}
