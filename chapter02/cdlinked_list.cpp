#include <stdio.h>
#include <malloc.h>
#include "dlinked_list.h"

void CreateCDLinkedListF(DLinkNode *&list, const ElemType *a, int n) {
    // 创建头结点
    list = (DLinkNode *) malloc(sizeof(DLinkNode));
    // 初始化头结点的前驱和后继为list
    list->prior = list->next = list;

    DLinkNode *p = nullptr;
    for (int i = 0; i < n; ++i) {
        p = (DLinkNode *) malloc(sizeof(DLinkNode));
        p->data = a[i];

        // 将p结点插到头结点之后
        p->next = list->next;
        list->next->prior = p;
        p->prior = list;
        list->next = p;
    }
}

void CreateCDLinkedListR(DLinkNode *&list, const ElemType *a, int n) {
    // 创建头结点
    list = (DLinkNode *) malloc(sizeof(DLinkNode));
    // 尾指针,初始化指向头结点
    DLinkNode *r = list;

    DLinkNode *p = nullptr;
    for (int i = 0; i < n; ++i) {
        p = (DLinkNode *) malloc(sizeof(DLinkNode));
        p->data = a[i];
        // 将p插入到p结点之后
        r->next = p;
        p->prior = r;
        // r继续指向尾结点
        r = p;
    }

    // 设置尾结点的next为list
    r->next = list;
    // list的prior为r
    list->prior = r;
}

void InitList(DLinkNode *&list) {
    list = (DLinkNode *) malloc(sizeof(DLinkNode));
    list->prior = list->next = list;
}

void DestroyList(DLinkNode *&list) {
    DLinkNode *p = list->next;

    while (p != list) {
        // 释放空间
        free(p->prior);

        p = p->next;
    }

    // 循环结束p指向尾结点
    free(p);
}

bool ListEmpty(DLinkNode *list) {
    return list->next == list;
}

int ListLength(DLinkNode *list) {
    int length = 0;

    // p指向首节点
    DLinkNode *p = list->next;

    while (p != list) {
        length++;
        p = p->next;
    }

    return length;
}

void DispList(DLinkNode *list) {
    // p指向首结点
    DLinkNode *p = list->next;

    while (p != list) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

bool GetElem(DLinkNode *list, int i, ElemType &e) {
    if (i <= 0) {
        printf("i必须大于0");
        return false;
    }

    // list是空表
    if (ListEmpty(list)) {
        printf("list是空表\n");
        return false;
    } else {
        int j = 1;
        DLinkNode *p = list->next;
        while (j < i) {
            if (p->next == list) {
                break;
            }
            j++;
            p = p->next;
        }

        if (j != i) {
            // 没找到
            printf("没找到第%d个元素\n", i);
            return false;
        } else {
            e = p->data;
            return true;
        }
    }
}

int LocateElem(DLinkNode *list, ElemType &e) {
    int i = 1;

    DLinkNode *p = list->next;

    while (p != list) {
        if (e == p->data) {
            break;
        }
        p = p->next;
        i++;
    }

    // 不存在值为e的结点，返回0
    if (p == list) {
        return 0;
    } else {
        return i;
    }
}

bool ListInsert(DLinkNode *&list, int i, ElemType e) {
    if (i <= 0) {
        printf("i必须大于0");
        return false;
    }

    DLinkNode *p = list;
    DLinkNode *s = nullptr;

    // 循环链表是找不到第0个元素的(不能从0开始找)，所以i=1需要单独处理
    // i == 1时，无论是否是空表都一样处理
    if (i == 1) {
        s = (DLinkNode *) malloc(sizeof(DLinkNode));
        s->data = e;
        s->next = p->next;
        p->next->prior = s;
        s->prior = p;
        p->next = s;
        return true;
    } else {
        if (ListEmpty(list)) {
            printf("当前list是空表，i不能大于1\n");
            return false;
        }

        /*
         * 找第i-1个结点，若存在则插入
         */
        int j = 1;
        // p指向首结点
        p = list->next;

        while (j < i - 1) {
            if (p->next == list) {
                break;
            }
            j++;
            p = p->next;
        }

        if (j != i-1) {
            // 没找到第i-1个元素
            printf("不存在第%d个元素\n", i - 1);
            return false;
        } else {
            s = (DLinkNode *) malloc(sizeof(DLinkNode));
            s->data = e;
            s->next = p->next;
            p->next->prior = s;
            s->prior = p;
            p->next = s;

            return true;
        }
    }
}

bool ListDelete(DLinkNode *&list, int i, ElemType &e) {
    // p指向首结点
    DLinkNode *p = list->next;
    DLinkNode *q = nullptr;

    if (i <= 0) {
        printf("i必须大于0");
        return false;
    }

    // list是空表
    if (ListEmpty(list)) {
        printf("当前list是空表\n");
        return false;
    } else {
        // 循环链表是找不到第0个元素的(不能从0开始找)，所以i=1需要单独处理
        if (i == 1) {
            q = list->next;
            e = q->data;
            list->next = q->next;
            q->next->prior = list;
            free(q);
            return true;
        } else {
            /*
             * 找第i-1个结点
             */
            int j = 1;

            while (j < i - 1) {
                if (p->next == list) {
                    break;
                }
                j++;
                p = p->next;
            }

            if (j != i-1) {
                // 没找到第i-1个元素
                printf("不存在第%d个元素\n", i - 1);
                return false;
            } else {
                // 删除q节点
                q = p->next;
                e = q->data;
                p->next = q->next;
                q->next->prior = p;
                free(q);

                return true;
            }
        }
    }
}
