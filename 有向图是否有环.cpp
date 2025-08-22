/*判断有向图中是否有环。
输入格式
输入数据第一行是一个正整数，表示n个有向图，其余数据分成n组，
每组第一个为一个整数，表示图中的顶点个数n，顶点数不超过100，
之后为有向图的邻接矩阵。
输出格式
输出结果为一行，如果有环，则输出1，如果无环，则输出0。
按顺序输出这n个有向图的判断结果，前后结果的输出不加空格。
样例输入
3
2
0 1
0 0
3
0 1 1
0 0 0
0 0 0
4
0 1 0 0
0 0 0 1
0 0 0 1
1 0 0 0
样例输出
001*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct Stack{
	int stack[MAX_SIZE];
	int top;
}Stack;
Stack* InitStack(){
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
int main(){
	int n;
	scanf("%d",&n);
	int count_result[MAX_SIZE]={0};
	int count=0;
	//n组数据
	for(int k=0;k<n;k++){
		int arcs[MAX_SIZE][MAX_SIZE]={0};	
		Stack* st=InitStack();
		int m;
		int topo=0; //拓扑数组的计数变量
		int indegree[MAX_SIZE]={0};
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&arcs[i][j]);
				if(arcs[i][j]==1){
					indegree[j]++;
				}
			}
		}
		//入度为0的压栈
		for(int i=0;i<m;i++){
			if(indegree[i]==0){
				Push(st,i);
			}
		}
		//拓扑排序
		while(!IsEmpty(st)){
			int i=Pop(st);
			topo++;
			for(int j=0;j<m;j++){
				if(arcs[i][j]==1){
					indegree[j]--;
				if(indegree[j]==0)
					Push(st,j);
				}//if
			}//for
		}//while
		if(topo==m){
			count_result[count++]=0;
		}
		else{
			count_result[count++]=1;
		}
	}
	for(int i=0;i<count;i++)
	printf("%d",count_result[i]);
	return 0;
}
