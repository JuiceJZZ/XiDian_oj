#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 1000
//�Թ��ĸ߶�m,�Թ��Ŀ��n
int m,n;
//�Թ��ĳ�ʼ����
int startx,starty,endx,endy;
//������
typedef struct Node{
	int x,y;
	int direction;//1-->�ң�2-->�£�3-->��4-->��
}Node;
//����һ����ʾ��ǰ��ı���
Node now;
//����һ����־����flag,�����жϵݹ����
int flag=0;
//�Թ�����
int maze[MAXSIZE][MAXSIZE];
//����һ������������ȱ���ʱʹ�õ�ջ,�洢·��������洢��
typedef struct Stack{
	Node stack[MAXSIZE*MAXSIZE];
	int top;
}Stack;
//�������飬�洢ÿ��������x,y������
int d[4][2]={{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // ��0����1����2����3
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
	//��ջ��Ԫ����ӽ���
	now=TopStack(st);
	//�ж�now���ĸ�������0����1����2����3
	for(int i=0;i<4;i++){
		//i=3����Ϊ����ģ���Ϊ���ĸ���������һ������˵���ĸ����򶼱�������Ҳû�д����ݹ飩�����Ҫ���⿼��
		//ÿ�εݹ鷵�ػ��������ж�flag�ǲ���1
		if(isStackEmpty(st))
		return;
		if(flag==1)
		return;
		//����߽紦��
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
		     flag = 1; // �ҵ��յ�
		     return;
	    } else {
		             Dfs(st); // �����ݹ�����
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
	maze[startx-1][starty-1]=1;//������Ϊ�ѷ���
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
			else//�յ㷽��Ĭ��Ϊ1
			printf("(%d,%d,1)",res[i].x,res[i].y);
		}
	}
	return 0;
}
