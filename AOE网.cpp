#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100
typedef struct Stack {
    int stack[MAX_SIZE];
    int top;
} Stack;
void Push(Stack* st, int data) {
    st->stack[++st->top] = data;
}
int Pop(Stack* st) {
    return st->stack[st->top--];
}
int main() {
    int n;
    scanf("%d", &n);
    int arcs[MAX_SIZE][MAX_SIZE] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arcs[i][j]);
        }
    }
    int indegree[MAX_SIZE] = {0};
    // 计算每个节点的入度
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (arcs[i][j] != 0) {
                indegree[j]++;
            }
        }
    }
    int ETV[MAX_SIZE] = {0};  // 事件的最早开始时间
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->top = -1;
    // 找到入度为0的节点
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            Push(st, i);
        }
    }
    int processed = 0;
    // 拓扑排序
    while (st->top != -1) {
        int i = Pop(st);
        processed++;
        // 遍历所有邻接节点，更新入度，并计算ETV
        for (int j = 0; j < n; j++) {
            if (arcs[i][j] != 0) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    Push(st, j);
                }
                if (ETV[i] + arcs[i][j] > ETV[j]) {
                    ETV[j] = ETV[i] + arcs[i][j];
                }
            }
        }
    }
    // 如果处理的节点数不等于总节点数，说明有环
    if (processed != n) {
        printf("NO\n");
    } else {
        printf("%d\n", ETV[n - 1]);  // 输出到汇点的最早开始时间
    }
    free(st);
    return 0;
}
