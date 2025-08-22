#define _CRT_SECURE_NO_WARNINGS // 禁用安全警告
#include<stdio.h> // 标准输入输出库
#include<stdlib.h> // 标准库，包含malloc和free函数

// 定义路径结构体，用于存储当前位置和方向
typedef struct Path {
	int x; // 当前x坐标
	int y; // 当前y坐标
	int dir; // 当前方向
} Path;

// 定义链栈节点结构体，用于存储路径信息和指向下一个节点的指针
typedef struct STNode {
	Path path; // 路径信息
	struct STNode* next; // 指向下一个节点的指针
} STNode, *LinkStack;

// 函数声明
void Push(LinkStack* S, Path path); // 入栈操作
Path Pop(LinkStack* S); // 出栈操作
void Initmaze(int maze[100][100], int m, int n); // 初始化迷宫
void Print(LinkStack* S); // 打印路径

int main() {
	int m, n; // 迷宫的行数和列数
	int x1, y1, x2, y2; // 起点和终点的坐标
	int maze[100][100] = { 0 }; // 迷宫数组，初始化为0
	int i, j, k; // 循环变量
	int x[4] = { 1,0,-1,0 }; // x方向的变化量
	int y[4] = { 0,1,0,-1 }; // y方向的变化量
	int dir[4] = { 1,2,3,4 }; // 向每个方向的编号，题目要求右和下优先
	LinkStack S = NULL; // 初始化链栈为空
	Path path; // 定义路径变量
	int flag = 1; // 标志变量，用于判断是否需要回溯

	scanf("%d %d", &m, &n); // 输入迷宫的行数和列数
	scanf("%d %d", &x1, &y1); // 输入起点坐标
	scanf("%d %d", &x2, &y2); // 输入终点坐标
	Initmaze(maze, m, n); // 初始化迷宫

	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &maze[i][j]); // 输入迷宫数据
		}
	}

	path.x = x1; // 设置起点x坐标
	path.y = y1; // 设置起点y坐标
	path.dir = 0; // 设置起点方向为0
	Push(&S, path); // 将起点压入栈中
	maze[S->path.x][S->path.y]=1; // 标记起点已访问

	while (S != NULL) {
		if (S->path.x == x2 && S->path.y == y2) { // 如果到达终点
			break; // 退出循环
		}
		for (k = 0; k < 4; k++) { // 尝试四个方向
			if (maze[S->path.x + y[k]][S->path.y + x[k]] == 0) { // 如果该方向可走
				S->path.dir = dir[k]; // 更新当前方向
				maze[S->path.x][S->path.y] = 1; // 标记当前点已访问

				path.x = S->path.x + y[k]; // 更新新路径的x坐标
				path.y = S->path.y + x[k]; // 更新新路径的y坐标
				path.dir = 1; // 设置新路径的方向为1
				Push(&S, path); // 将新路径压入栈中

				flag = 0; // 重置标志变量
				break; // 退出循环
			}
		}
		if (flag == 1) { // 如果无法前进
			maze[S->path.x][S->path.y] = 1; // 标记当前点已访问
			Pop(&S); // 弹出当前路径
		}
		flag = 1; // 重置标志变量
	}

	if (S == NULL) // 如果栈为空，表示没有找到路径
		printf("no"); // 输出"no"
	else
		Print(&S); // 否则打印路径

	return 0; // 返回0，程序结束
}

// 入栈操作，将路径压入栈中
void Push(LinkStack* S, Path path) {
	LinkStack q = (LinkStack)malloc(sizeof(STNode)); // 分配新节点内存
	q->path = path; // 设置新节点的路径信息
	q->next = (*S); // 将新节点的next指针指向当前栈顶节点
	(*S) = q; // 更新栈顶指针为新节点
}

// 出栈操作，从栈中弹出一个路径并返回
Path Pop(LinkStack* S) {
	LinkStack q = (*S); // 获取当前栈顶节点
	Path path = q->path; // 保存当前栈顶节点的路径信息
	(*S) = (*S)->next; // 更新栈顶指针为下一个节点
	free(q); // 释放原栈顶节点的内存
	return path; // 返回路径信息
}

// 初始化迷宫，将迷宫边界设置为不可通行（值为1）
void Initmaze(int maze[100][100], int m, int n) {
	int i, j; // 循环变量
	for (i = 0; i < m+2; i++) { // 遍历所有行
		for (j = 0; j < n+2; j++) { // 遍历所有列
			maze[i][j] = 1; // 将边界设置为1，表示不可通行
		}
	}
}

// 打印路径，从栈中依次弹出路径并打印
void Print(LinkStack* S) {
	LinkStack q = NULL; // 临时栈，用于反转路径顺序
	while ((*S) != NULL) { // 当原栈不为空时
		Push(&q, Pop(S)); // 将原栈中的路径依次弹出并压入临时栈中
	}
	while (q != NULL) { // 当临时栈不为空时
		Path a = Pop(&q); // 弹出临时栈顶的路径
		printf("(%d,%d,%d)", a.x, a.y, a.dir); // 打印路径信息
		if (q != NULL) // 如果临时栈不为空，打印逗号分隔符
			printf(",");
	}
}
