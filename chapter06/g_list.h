#ifndef CHAPTER06_GLNODE_H
#define CHAPTER06_GLNODE_H

typedef char ElemType;

// 广义表结点类型
typedef struct lnode {
    // 结点类型表示,0：原子;1：表/子表
    int tag;

    union {
        // 存放原子值
        ElemType data;
        // 指向子表的指针
        struct lnode *sublist;
    } val;

    // 指向下一个元素
    struct lnode *link;
} GLNode;

/**
 * 求广义表的长度
 * @param glNode
 * @return
 */
int GLLength(GLNode *g);

/**
 * 求广义表的深度
 * @param g
 * @return
 */
int GLDepth(GLNode *g);

/**
 * 输出广义表
 * @param g
 */
void DispGL(GLNode *g);


/**
 * 建立广义表的链式存储结构
 * @param s
 * @return
 */
GLNode *CreateGL(char *s);

/**
 * 销毁广义表
 */
void DestroyGL(GLNode *&g);

#endif //CHAPTER06_GLNODE_H
