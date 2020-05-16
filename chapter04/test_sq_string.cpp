#include <stdio.h>
#include "sq_string.h"

int main() {
    char cstr[] = {'a', 'b', 'c', 'd', 'e', 'f', '\0'};

    SqString str;
    StrAssign(str, cstr);
    printf("init str len: %d\n", StrLength(str));
    printf("init str disp:\n");
    DispStr(str);

    SqString s;
    StrCopy(s, str);
    printf("copy str to s len: %d\n", StrLength(s));
    printf("copy str to s disp:");
    DispStr(s);

    char cstr2[] = {'b', 'b', 'c', '\0'};
    SqString s2;
    StrAssign(s2, cstr2);

    bool flag = StrEqual(s, s2);
    printf("equal flag: %d\n", flag);

    SqString ret = Concat(s, s2);
    printf("concat s, s2: ");
    DispStr(ret);

    SqString subStr = SubStr(ret, 3, 4);
    printf("sub str: ");
    DispStr(subStr);

    SqString insStr = InsString(str, 3, s2);
    printf("ins str: ");
    DispStr(insStr);

    SqString delStr = DelString(s, 3, 2);
    printf("del str: ");
    DispStr(delStr);

    SqString repStr = RepStr(s, 3, 2, s2);
    printf("rep str: ");
    DispStr(repStr);

    return 0;
}