// 输出迷宫所有路径，并求第一条最短路径长度及最短路径
#include <stdio.h>
#include "sq_stack.h"

#define M 4
#define N 4
int mg[M + 2][N + 2] =
        {
                {1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 1, 1},
                {1, 0, 1, 0, 0, 1},
                {1, 0, 0, 0, 1, 1},
                {1, 1, 0, 0, 0, 1},
                {1, 1, 1, 1, 1, 1}
        };
// 最短路径
Box path[MAX_SIZE];
// 最短路径长度
int minLen = MAX_SIZE;

void print(SqStack *stack) {
    printf("一条迷宫路径如下：\n");

    Box tmp[MAX_SIZE];

    for (int j = 0; j < stack->top + 1; ++j) {
        printf("(%d, %d)", stack->data[j].i, stack->data[j].j);
        tmp[j].i = stack->data[j].i;
        tmp[j].j = stack->data[j].j;
    }

    if (stack->top + 1 < minLen) {
        // 将最短路径存起来
        for (int i = 0; i < stack->top + 1; ++i) {
            path[i].i = tmp[i].i;
            path[i].j = tmp[i].j;
        }

        minLen = stack->top + 1;
    }

    printf("\n");
}

/**
 * 查找迷宫路径
 * @param xi 入口行号
 * @param yi 入口列号
 * @param xe 出口行号
 * @param ye 出口列号
 * @return
 */
void MgPath(int xi, int yi, int xe, int ye) {
    bool find;

    // 路径栈
    SqStack *stack = nullptr;
    InitStack(stack);

    Box e;
    // 初始化入口
    e.i = xi;
    e.j = yi;
    e.di = -1;
    // e进栈
    Push(stack, e);
    // 将入口的迷宫值置为-1,避免重复走到该方块
    mg[xi][yi] = -1;

    int i, j, i1 = 0, j1 = 0, di, k;
    while (!StackEmpty(stack)) {
        GetTop(stack, e);

        i = e.i;
        j = e.j;
        di = e.di;

//        printf("i: %d, j: %d, di: %d\n", i, j, di);

        // 找到了出口，输出路径
        if (i == xe && j == ye) {
            // 找到出口，输出并回溯继续搜索其它路径
            print(stack);
            Pop(stack, e);
            mg[e.i][e.j] = 0;
            continue;
        }

        find = false;
        // 寻找方块(i, j)的下一个相邻可走方块(i1, j1)
        while (di < 4 && !find) {
            di++;
            switch (di) {
                case 0:
                    i1 = i-1;
                    j1 = j;
                    break;
                case 1:
                    i1 = i;
                    j1 = j + 1;
                    break;
                case 2:
                    i1 = i + 1;
                    j1 = j;
                    break;
                case 3:
                    i1 = i;
                    j1 = j - 1;
                    break;
            }

            if (mg[i1][j1] == 0) {
                // 找到一个相邻可走方块
                find = true;
            }
        }

        // 找到一个相邻可走方块
        if (find) {
            // 修改原栈顶元素的di
            stack->data[stack->top].di = di;
            e.i = i1;
            e.j = j1;
            e.di = -1;
            Push(stack, e);
            // 将(i1, j1)迷宫值置为-1，避免重复走到该方块
            mg[i1][j1] = -1;
        }
        // 没有路径可走，退栈
        else {
            Pop(stack, e);
            // 让退栈方块的位置变为其他路径可走方块
            mg[e.i][e.j] = 0;
        }
    }

    DestroyStack(stack);

    // 输出最短路径
    printf("最短路径：\n");
    for (int l = 0; l < minLen; ++l) {
        printf("(%d,%d) ",path[l].i,path[l].j);
    }
    printf("\n");

    printf("最短路径长度：%d\n", minLen);

    printf("\n");
}

int main() {
    MgPath(1, 1, M, N);

    return 0;
}