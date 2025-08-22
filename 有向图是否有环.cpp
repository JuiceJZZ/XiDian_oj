/*�ж�����ͼ���Ƿ��л���
�����ʽ
�������ݵ�һ����һ������������ʾn������ͼ���������ݷֳ�n�飬
ÿ���һ��Ϊһ����������ʾͼ�еĶ������n��������������100��
֮��Ϊ����ͼ���ڽӾ���
�����ʽ
������Ϊһ�У�����л��������1������޻��������0��
��˳�������n������ͼ���жϽ����ǰ������������ӿո�
��������
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
�������
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
	//n������
	for(int k=0;k<n;k++){
		int arcs[MAX_SIZE][MAX_SIZE]={0};	
		Stack* st=InitStack();
		int m;
		int topo=0; //��������ļ�������
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
		//���Ϊ0��ѹջ
		for(int i=0;i<m;i++){
			if(indegree[i]==0){
				Push(st,i);
			}
		}
		//��������
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
