#include <stdio.h>
#include "b_tree.h"

int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    BTNode *b;
    CreateBTree(b, str);
    printf("disp: ");
    DisplayBTree(b);

    printf("\nheight: %d", BTHeight(b));

    ElemType x = 'I';
    BTNode *p = FindNode(b, x);
    if (nullptr != p) {
        printf("\nx: %c\n", p->data);
    } else {
        printf("\n未找到: %c\n", x);
    }

    DestroyBTree(b);
    return 0;
}