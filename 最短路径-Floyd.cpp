/*求图中任意两个顶点之间的最短路径。
输入格式
	输入数据第一行是一个正整数，表示图中的顶点个数n（
	顶点将分别按0，1，…，n-1进行编号）。之后的n行每行都包含n个整数，
	第i行第j个数表示顶点i-1和顶点j-1之间的边长，用10000来表示两个顶点之间无边。
	后面每行2个数字，表示一对待求最短路径的顶点，用-1 -1表示输入结束，
	-1 -1不求解。
输出格式
每对待求最短路径的顶点输出两行数据：第一行输出两个顶点间的最短路径长度，
第二行输出最短路径，要按顺序输出顶点编号序列，顶点间用空格隔开。当
两个顶点间没有路径时，只在一行上输出字符串“NO”。
样例输入
7
0 12 10000 10000 10000 10000 10000
12 0 10000 10000 3 10000 10000
10000 10000 0 10000 10000 21 11
10000 10000 10000 0 10000 10000 10000
10000 3 10000 10000 0 10000 8
10000 10000 21 10000 10000 0 10000
10000 10000 11 10000 8 10000 0
0 2
0 3
5 0
2 1
1 5
-1 -1
样例输出
34
0 1 4 6 2
NO
55
5 2 6 4 1 0
22
2 6 4 1
43
1 4 6 2 5*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 100
const int MAX_VALUE=10000;
typedef struct Stack{
	int stack[MAX_SIZE];
	int top;
}Stack;
Stack* InitSatck(){
	Stack* st=(Stack*)malloc(sizeof(Stack));
	st->top=-1;
	return st;
}
bool IsEmpty(Stack* st){
	return st->top==-1;
}
void Push(Stack* st,int data){
	st->stack[++st->top]=data;
}
int Pop(Stack* st){
	return st->stack[st->top--];
}
void PrintRoad(Stack* st){
	while(!IsEmpty(st)){
		printf("%d ",Pop(st));
	}
	printf("\n");
}
int main(){
	int n;
	Stack* st=InitSatck();
	scanf("%d",&n);
	int arcs[MAX_SIZE][MAX_SIZE]={0};
	int D[MAX_SIZE][MAX_SIZE]={0};
	int Path[MAX_SIZE][MAX_SIZE]={0};
	//构造邻接矩阵和初始化D数组和Path数组
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arcs[i][j]);
			D[i][j]=arcs[i][j];
			if(D[i][j]<MAX_VALUE&&i!=j){
				Path[i][j]=i;
			}
			else
			Path[i][j]=-1;
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(D[i][k]+D[k][j]<D[i][j]){
					D[i][j]=D[i][k]+D[k][j];
					Path[i][j]=Path[k][j];
				}
			}
		}
	}
	while(true){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		if(v1==-1&&v2==-1)
		break;
		if(D[v1][v2]==MAX_VALUE){
			printf("NO\n");
		}
		else{
			printf("%d\n",D[v1][v2]);
			//将路径压栈
			int v3=Path[v1][v2];
			Push(st,v2);
			while(v3!=v1){
				Push(st,v3);
				v3=Path[v1][v3];
			}
			Push(st,v1);
			PrintRoad(st);
		}
	}
	return 0;
}
