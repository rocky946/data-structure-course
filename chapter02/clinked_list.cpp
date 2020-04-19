#include <stdio.h>
#include <malloc.h>
#include "clinked_list.h"

void CreateCLinkedListF(LinkNode *&list,  const ElemType *a, int n) {
    // 创建头结点
    list = (LinkNode *) malloc(sizeof(LinkNode));
    // 头插法创建循环单链表，头结点next为自己
    list->next = list;

    // 数据结点
    LinkNode *p = nullptr;

    for (int i = 0; i < n; ++i) {
        // 创建数据结点
        p = (LinkNode *) malloc(sizeof(LinkNode));
        p->data = a[i];

        // 将结点p插入到原首结点之前，头结点之后
        p->next = list->next;

        list->next = p;
    }
}

void CreateCLinkedListR(LinkNode *&list, const ElemType *a, int n) {
    // 创建头结点
    list = (LinkNode *) malloc(sizeof(LinkNode));
    // 初始化空链表
    list->next = nullptr;
    // 尾指针，始终指向尾结点，初始时指向头结点
    LinkNode *r = list;

    // 数据结点
    LinkNode *p = nullptr;

    for (int i = 0; i < n; ++i) {
        // 创建数据结点
        p = (LinkNode *) malloc(sizeof(LinkNode));
        p->data = a[i];

        // 将p插入到尾结点之后
        r->next = p;
        // r重新指向尾结点
        r = p;
    }

    // 尾插法创建循环单链表，最终将尾结点的next域置为list
    r->next = list;
}

void InitList(LinkNode *&list) {
    list = (LinkNode *) malloc(sizeof(LinkNode));
    list->next = list;
}

void DestroyList(LinkNode *&list) {
    // pre指向p的前驱结点
    LinkNode *pre = list;
    LinkNode *p = list->next;

    while (p != list) {
        // 释放空间
        free(pre);

        // pre、p后移一个结点
        pre = p;
        p = p->next;
    }

    // 循环结束p指向尾结点
    free(p);
}

bool ListEmpty(LinkNode *list) {
    return list->next == list;
}

int ListLength(LinkNode *list) {
    int length = 0;

    // p指向首节点
    LinkNode *p = list->next;

    while (p != list) {
        length++;
        p = p->next;
    }

    return length;
}

void DispList(LinkNode *list) {
    // p指向首结点
    LinkNode *p = list->next;

    while (p != list) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}


bool GetElem(LinkNode *list, int i, ElemType &e) {
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
        LinkNode *p = list->next;
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

int LocateElem(LinkNode *list, ElemType &e) {
    int i = 1;

    LinkNode *p = list->next;

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

bool ListInsert(LinkNode *&list, int i, ElemType e) {
    if (i <= 0) {
        printf("i必须大于0");
        return false;
    }

    LinkNode *p = list;
    LinkNode *s = nullptr;

    // 循环链表是找不到第0个元素的(不能从0开始找)，所以i=1需要单独处理
    // i == 1时，无论是否是空表都一样处理
    if (i == 1) {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    } else {
        if (p->next == list) {
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
            s = (LinkNode *) malloc(sizeof(LinkNode));
            s->data = e;
            s->next = p->next;
            p->next = s;

            return true;
        }
    }
}

bool ListDelete(LinkNode *&list, int i, ElemType &e) {
    // p指向首结点
    LinkNode *p = list->next;
    LinkNode *q = nullptr;

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
                free(q);

                return true;
            }
        }
    }
}
