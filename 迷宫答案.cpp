#define _CRT_SECURE_NO_WARNINGS // ���ð�ȫ����
#include<stdio.h> // ��׼���������
#include<stdlib.h> // ��׼�⣬����malloc��free����

// ����·���ṹ�壬���ڴ洢��ǰλ�úͷ���
typedef struct Path {
	int x; // ��ǰx����
	int y; // ��ǰy����
	int dir; // ��ǰ����
} Path;

// ������ջ�ڵ�ṹ�壬���ڴ洢·����Ϣ��ָ����һ���ڵ��ָ��
typedef struct STNode {
	Path path; // ·����Ϣ
	struct STNode* next; // ָ����һ���ڵ��ָ��
} STNode, *LinkStack;

// ��������
void Push(LinkStack* S, Path path); // ��ջ����
Path Pop(LinkStack* S); // ��ջ����
void Initmaze(int maze[100][100], int m, int n); // ��ʼ���Թ�
void Print(LinkStack* S); // ��ӡ·��

int main() {
	int m, n; // �Թ�������������
	int x1, y1, x2, y2; // �����յ������
	int maze[100][100] = { 0 }; // �Թ����飬��ʼ��Ϊ0
	int i, j, k; // ѭ������
	int x[4] = { 1,0,-1,0 }; // x����ı仯��
	int y[4] = { 0,1,0,-1 }; // y����ı仯��
	int dir[4] = { 1,2,3,4 }; // ��ÿ������ı�ţ���ĿҪ���Һ�������
	LinkStack S = NULL; // ��ʼ����ջΪ��
	Path path; // ����·������
	int flag = 1; // ��־�����������ж��Ƿ���Ҫ����

	scanf("%d %d", &m, &n); // �����Թ�������������
	scanf("%d %d", &x1, &y1); // �����������
	scanf("%d %d", &x2, &y2); // �����յ�����
	Initmaze(maze, m, n); // ��ʼ���Թ�

	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &maze[i][j]); // �����Թ�����
		}
	}

	path.x = x1; // �������x����
	path.y = y1; // �������y����
	path.dir = 0; // ������㷽��Ϊ0
	Push(&S, path); // �����ѹ��ջ��
	maze[S->path.x][S->path.y]=1; // �������ѷ���

	while (S != NULL) {
		if (S->path.x == x2 && S->path.y == y2) { // ��������յ�
			break; // �˳�ѭ��
		}
		for (k = 0; k < 4; k++) { // �����ĸ�����
			if (maze[S->path.x + y[k]][S->path.y + x[k]] == 0) { // ����÷������
				S->path.dir = dir[k]; // ���µ�ǰ����
				maze[S->path.x][S->path.y] = 1; // ��ǵ�ǰ���ѷ���

				path.x = S->path.x + y[k]; // ������·����x����
				path.y = S->path.y + x[k]; // ������·����y����
				path.dir = 1; // ������·���ķ���Ϊ1
				Push(&S, path); // ����·��ѹ��ջ��

				flag = 0; // ���ñ�־����
				break; // �˳�ѭ��
			}
		}
		if (flag == 1) { // ����޷�ǰ��
			maze[S->path.x][S->path.y] = 1; // ��ǵ�ǰ���ѷ���
			Pop(&S); // ������ǰ·��
		}
		flag = 1; // ���ñ�־����
	}

	if (S == NULL) // ���ջΪ�գ���ʾû���ҵ�·��
		printf("no"); // ���"no"
	else
		Print(&S); // �����ӡ·��

	return 0; // ����0���������
}

// ��ջ��������·��ѹ��ջ��
void Push(LinkStack* S, Path path) {
	LinkStack q = (LinkStack)malloc(sizeof(STNode)); // �����½ڵ��ڴ�
	q->path = path; // �����½ڵ��·����Ϣ
	q->next = (*S); // ���½ڵ��nextָ��ָ��ǰջ���ڵ�
	(*S) = q; // ����ջ��ָ��Ϊ�½ڵ�
}

// ��ջ��������ջ�е���һ��·��������
Path Pop(LinkStack* S) {
	LinkStack q = (*S); // ��ȡ��ǰջ���ڵ�
	Path path = q->path; // ���浱ǰջ���ڵ��·����Ϣ
	(*S) = (*S)->next; // ����ջ��ָ��Ϊ��һ���ڵ�
	free(q); // �ͷ�ԭջ���ڵ���ڴ�
	return path; // ����·����Ϣ
}

// ��ʼ���Թ������Թ��߽�����Ϊ����ͨ�У�ֵΪ1��
void Initmaze(int maze[100][100], int m, int n) {
	int i, j; // ѭ������
	for (i = 0; i < m+2; i++) { // ����������
		for (j = 0; j < n+2; j++) { // ����������
			maze[i][j] = 1; // ���߽�����Ϊ1����ʾ����ͨ��
		}
	}
}

// ��ӡ·������ջ�����ε���·������ӡ
void Print(LinkStack* S) {
	LinkStack q = NULL; // ��ʱջ�����ڷ�ת·��˳��
	while ((*S) != NULL) { // ��ԭջ��Ϊ��ʱ
		Push(&q, Pop(S)); // ��ԭջ�е�·�����ε�����ѹ����ʱջ��
	}
	while (q != NULL) { // ����ʱջ��Ϊ��ʱ
		Path a = Pop(&q); // ������ʱջ����·��
		printf("(%d,%d,%d)", a.x, a.y, a.dir); // ��ӡ·����Ϣ
		if (q != NULL) // �����ʱջ��Ϊ�գ���ӡ���ŷָ���
			printf(",");
	}
}
