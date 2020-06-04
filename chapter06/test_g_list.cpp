#include <stdio.h>
#include "g_list.h"

int main() {
    char s[] = {'(', 'a', ',', '(', 'a', ',', 'b', ')', ')', '\0'};
    GLNode *g = CreateGL(s);
    printf("disp: ");
    DispGL(g);
    printf("\n")
    printf("len: %d\n", GLLength(g));
    printf("depth: %d\n", GLDepth(g));
    DestroyGL(g);

    return 0;
}