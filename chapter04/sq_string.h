#ifndef CHAPTER04_SQ_STRING_H
#define CHAPTER04_SQ_STRING_H

#define MAX_SIZE 100

// 顺序串类型
typedef struct {
    // 存放串字符
    char data[MAX_SIZE];
    // 存放串长
    int length;
} SqString;

/**
 * 生成串
 */
void StrAssign(SqString &s, char cstr[]);

/**
 * 销毁串
 * @param s
 */
void DestroyStr(SqString &s);

/**
 * 将顺序串t复制给顺序串s
 */
void StrCopy(SqString &s, SqString t);

/**
 * 判断顺序串s与t是否相等
 * @param s
 * @param t
 * @return
 */
bool StrEqual(SqString s, SqString t);

/**
 * 返回顺序串s的长度
 * @param s
 * @return
 */
int StrLength(SqString s);

/**
 * 将顺序串s和t连接形成新的结果串
 * @param s
 * @param t
 * @return
 */
SqString Concat(SqString s, SqString t);

 /**
  * 返回顺序串s中从第i(1<=i<=n)个字符开始的由连续j个字符组成的子串
  * @param s
  * @param i
  * @param j
  * @return
  */
SqString SubStr(SqString s, int i, int j);

/**
 * 将顺序串s2插入到顺序串s1的第i(1<=i<=n+1)个位置上，并返回产生的结果串
 * @param s1
 * @param i
 * @param s2
 * @return
 */
SqString InsString(SqString s1, int i, SqString s2);

/**
 * 在顺序串s中删去从第i(1<=i<=n)个字符开始的长度为j的子串，并返回产生的结果
 * @param s
 * @param i
 * @param j
 * @return
 */
SqString DelString(SqString s, int i, int j);

/**
 * 在顺序串s中将第i(1<=i<=n)个字符开始的连续j个字符构成的子串用顺序串t替换，并返回产生的结果串
 * @param s
 * @param i
 * @param j
 * @param t
 * @return
 */
SqString RepStr(SqString s, int i, int j, SqString t);

/**
 * 输出顺序串s的所有元素值
 * @param s
 */
void DispStr(SqString s);

#endif //CHAPTER04_SQ_STRING_H
