#ifndef CHAPTER04_LINKED_STRING_H
#define CHAPTER04_LINKED_STRING_H

// 链串的结点类型
typedef struct snode {
    // 存放字符
    char data;
    // 指向下一个结点的指针
    struct snode *next;
} LinkStrNode;

/**
 * 生成串
 * @param s
 * @param cstr
 */
void StrAssign(LinkStrNode *&s, char cstr[]);

/**
 * 销毁串
 * @param s
 */
void DestroyStr(LinkStrNode *&s);

/**
 * 串复制，将t复制给s
 * @param s
 * @param t
 */
void StrCopy(LinkStrNode *&s, LinkStrNode *t);

/**
 * 判断串相等
 * @param s
 * @param t
 * @return
 */
bool StrEqual(LinkStrNode *s, LinkStrNode *t);

/**
 * 求串长
 * @param s
 * @return
 */
int StrLength(LinkStrNode *s);

/**
 * 串连接
 * @param s
 * @param t
 * @return
 */
LinkStrNode *Concat(LinkStrNode *s, LinkStrNode *t);

/**
 * 求字串
 * @param s
 * @param i
 * @param j
 * @return
 */
LinkStrNode *SubStr(LinkStrNode *s, int i, int j);

/**
 * 子串的插入
 * @param s
 * @param i
 * @param t
 * @return
 */
LinkStrNode *InsStr(LinkStrNode *s, int i, LinkStrNode *t);

/**
 * 子串的删除
 * @param s
 * @param i
 * @param j
 * @return
 */
LinkStrNode *DelStr(LinkStrNode *s, int i, int j);

/**
 * 子串的替换
 */
LinkStrNode *RepStr(LinkStrNode *s, int i, int j, LinkStrNode *t);

/**
 * 输出串
 * @param s
 */
void DispStr(LinkStrNode *s);

#endif //CHAPTER04_LINKED_STRING_H
