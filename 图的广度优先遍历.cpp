/*��֪����ͼ���ڽӾ����Ըþ���Ϊ����������������������������У����Ҹ���������ͼ����ͨ�����ĸ������ڱ���ʱ�����ж�����ѡʱ������ѡ����С�Ķ��㡣�����Ӷ���1��ʼ���б�����
�����ʽ
	��һ����1����������Ϊ�������n��n<100��������������Ϊ1��2������n���������ڽӾ���n��n�С�
�����ʽ
��2�С���һ�����Ϊ����ͼ�Ĺ�����������������У����Ϊ�����ţ�������֮���ÿո�������ڶ���Ϊ����ͼ����ͨ�����ĸ�����
��������
6
0 1 0 0 0 0
1 0 0 0 1 0
0 0 0 1 0 0
0 0 1 0 0 0
0 1 0 0 0 1
0 0 0 0 1 0
�������
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
	visited[i]=1;//ѹ�����ʱ������Ϊ�ѷ���
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

