#include <stdio.h>
#include "g_list.h"

/**
 * 求广义表g原子个数方法1
 * @param g
 * @return
 */
int Count1(GLNode *g) {
    int n = 0;

    GLNode *g1 = g->val.sublist;

    while (nullptr != g1) {
        if (g1->tag == 0) {
            n++;
        } else {
            n += Count1(g1);
        }

        g1 = g1->link;
    }

    return n;
}

/**
 * 求广义表g原子个数方法2
 * @param g
 * @return
 */
int Count2(GLNode *g) {
    int n = 0;
    if (nullptr != g) {
        if (g->tag == 0) {
            n++;
        } else {
            n += Count2(g->val.sublist);
        }

        n += Count2(g->link);
    }

    return n;
}

int main() {
    char s[] = {'(', 'a', ',', '(', 'a', ',', 'b', ')', ')', '\0'};
    GLNode *g = CreateGL(s);
    printf("disp: ");
    DispGL(g);
    printf("\n")
    printf("count1: %d\n", Count1(g));
    printf("count2: %d\n", Count2(g));
    DestroyGL(g);

    return 0;
}

