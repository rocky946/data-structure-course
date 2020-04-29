#include <stdio.h>
#include "sq_stack.h"

#define M 8
#define N 8
int mg[M + 2][N + 2] =
        {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
                {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
                {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
                {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };

/**
 * 查找迷宫路径
 * @param xi 入口行号
 * @param yi 入口列号
 * @param xe 出口行号
 * @param ye 出口列号
 * @return
 */
bool MgPath(int xi, int yi, int xe, int ye) {
    bool find;
    // 路径
    Box path[MAX_SIZE];

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

        printf("i: %d, j: %d, di: %d\n", i, j, di);
        
        // 找到了出口，输出路径
        if (i == xe && j == ye) {
            printf("一条迷宫路径如下：\n");
            
            k = 0;
            while (!StackEmpty(stack)) {
                Pop(stack, e);
                path[k++] = e;
            }

            while (k >= 1) {
                k--;
                printf("\t(%d, %d)", path[k].i, path[k].j);
                // 每输出5个方块后换行
                if ((k + 2) % 5 == 0) {
                    printf("\n");
                }
            }
            printf("\n");
            DestroyStack(stack);
            return true;
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
    // 没有可走路径，返回false
    return false;
}

int main() {
    if (!MgPath(1, 1, M, N)) {
        printf("该迷宫问题没有解!\n");
    }
    
    return 0;
}