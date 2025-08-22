#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 1000
//迷宫的高度m,迷宫的宽度n
int m,n;
//迷宫的初始坐标
int startx,starty,endx,endy;
//点坐标
typedef struct Node{
	int x,y;
	int direction;//1-->右，2-->下，3-->左，4-->上
}Node;
//创建一个表示当前点的变量
Node now;
//创建一个标志变量flag,用来判断递归结束
int flag=0;
//迷宫数组
int maze[MAXSIZE][MAXSIZE];
//创建一个用于深度优先遍历时使用的栈,存储路径（倒序存储）
typedef struct Stack{
	Node stack[MAXSIZE*MAXSIZE];
	int top;
}Stack;
//方向数组，存储每个方向上x,y的增量
int d[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 右0、下1、左2、上3
Stack* InitStack(){
	Stack* st=(Stack*)malloc(sizeof(Stack));
	st->top=-1;
	return st;
}
void PushElement(Stack* st,Node t){
	st->stack[++st->top]=t;
}
void PopElement(Stack* st){
	st->top--;
}
Node TopStack(Stack* st){
	return st->stack[st->top];
}
bool isStackEmpty(Stack* st){
	return st->top==-1;
}
void Dfs(Stack* st){
	if(flag==1)
	return;
	if(isStackEmpty(st))
	return;
	//把栈顶元素添加进来
	now=TopStack(st);
	//判断now的四个方向，右0、下1、左2、上3
	for(int i=0;i<4;i++){
		//i=3是最为特殊的，因为是四个方向的最后一个方向（说明四个方向都遍历完了也没有触发递归），因此要特殊考虑
		//每次递归返回回来，先判断flag是不是1
		if(isStackEmpty(st))
		return;
		if(flag==1)
		return;
		//特殊边界处理
		if (now.x == 1 && i == 3) {
		        PopElement(st);
		        if(isStackEmpty(st))
			    return;
				else
		        Dfs(st);
		    }
		if (now.x == m && i == 1) {
		       continue;
		}
	    if (now.y == 1 && i == 2) {
		       continue;
	    }
		if (now.y == n && i == 0) {
		    continue;
		}
	 if (maze[now.x + d[i][0] - 1][now.y + d[i][1] - 1] == 0){
	 	maze[now.x + d[i][0] - 1][now.y + d[i][1] - 1] =1;
	 	st->stack[st->top].direction=i+1;
	 	now.x+=d[i][0];
	 	now.y+=d[i][1];
	 	PushElement(st,now);
	 	if (now.x == endx && now.y == endy) {
		     flag = 1; // 找到终点
		     return;
	    } else {
		             Dfs(st); // 继续递归搜索
		         }
	 }
	else if(maze[now.x + d[i][0] - 1][now.y + d[i][1] - 1] == 1&&i==3){
		PopElement(st);
		if(isStackEmpty(st))
		return;
		else
		Dfs(st);
	}		
		}
}
int main(){
	scanf("%d%d",&m,&n);
	scanf("%d%d",&startx,&starty);
	scanf("%d%d",&endx,&endy);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&maze[i][j]);
		}
	}
	Stack* st=InitStack();
	now.x=startx;
	now.y=starty;
	now.direction=0;
	PushElement(st,now);
	maze[startx-1][starty-1]=1;//标记起点为已访问
	if(now.x==endx&&now.y==endy){
		printf("(%d,%d,0)",now.x,now.y);
		return -1;
	}
	else{
	Dfs(st);
	}
	Node res[MAXSIZE];
	int sum=0;
	if(isStackEmpty(st)){
		printf("no");
	}
	else{
		while(!isStackEmpty(st)){
			res[sum++]=TopStack(st);
			PopElement(st);
		}
		for(int i=sum-1;i>=0;i--){
			if(i!=0)
			printf("(%d,%d,%d),",res[i].x,res[i].y,res[i].direction);
			else//终点方向默认为1
			printf("(%d,%d,1)",res[i].x,res[i].y);
		}
	}
	return 0;
}
