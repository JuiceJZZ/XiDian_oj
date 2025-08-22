/*已知无向图的邻接矩阵，以该矩阵为基础，给出广度优先搜索遍历序列，并且给出该无向图的连通分量的个数。在遍历时，当有多个点可选时，优先选择编号小的顶点。（即从顶点1开始进行遍历）
输入格式
	第一行是1个正整数，为顶点个数n（n<100），顶点编号依次为1，2，…，n。后面是邻接矩阵，n行n列。
输出格式
共2行。第一行输出为无向图的广度优先搜索遍历序列，输出为顶点编号，顶点编号之间用空格隔开；第二行为无向图的连通分量的个数。
样例输入
6
0 1 0 0 0 0
1 0 0 0 1 0
0 0 0 1 0 0
0 0 1 0 0 0
0 1 0 0 0 1
0 0 0 0 1 0
样例输出
1 2 5 6 3 4
2
*/
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 200
typedef struct Queue{
	int front,rear;
	int queue[MAX_SIZE];
}Queue;
bool IsEmpty(Queue* qu){
	if(qu->front==qu->rear){
		return true;
	}
	else
	return false;
}
void Push(Queue* qu,int data){
	qu->queue[qu->rear]=data;
	qu->rear++;
}
int Pop(Queue* qu){
	return qu->queue[qu->front++];	
}
int main(){
	int n;
	int count_m=0;
	scanf("%d",&n);
	int arcs[MAX_SIZE][MAX_SIZE];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&arcs[i][j]);
		}
	}
	Queue* qu=(Queue*)malloc(sizeof(Queue));
	qu->front=qu->rear=0;
	int visited[MAX_SIZE]={0};
for(int i=1;i<=n;i++){
	if(visited[i]==0){
	Push(qu,i);
	visited[i]=1;//压入队列时就设置为已访问
	count_m++;
	while(!IsEmpty(qu)){
		int j=Pop(qu);
		printf("%d ",j);
		for(int k=1;k<=n;k++){
			if(arcs[j][k]!=0&&visited[k]==0){
				Push(qu,k);
				visited[k]=1;
				}
			}
		}
	}
}
	printf("\n%d\n",count_m);
	free(qu);
	return 0;
}

