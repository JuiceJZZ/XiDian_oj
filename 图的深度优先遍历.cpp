/*��֪����ͼ���ڽӾ����Ըþ���Ϊ����������������������������У����Ҹ���������ͼ����ͨ�����ĸ������ڱ���ʱ�����ж�����ѡʱ������ѡ����С�Ķ��㡣�����Ӷ���1��ʼ���б�����
�����ʽ
	��һ����1����������Ϊ�������n��n<100��������������Ϊ1��2������n���������ڽӾ���n��n�С�
�����ʽ
��2�С���һ�����Ϊ����ͼ��������������������У����Ϊ�����ţ�������֮���ÿո�������ڶ���Ϊ����ͼ����ͨ�����ĸ�����
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
#define MAX_SIZE 120
void Dfs(int arcs[MAX_SIZE][MAX_SIZE],int n,int i,int* visited);
int main(){
	int n;
	scanf("%d",&n);
	int arcs[MAX_SIZE][MAX_SIZE]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&arcs[i][j]);
		}
	}
	int count_m=0;
	int visited[MAX_SIZE]={0};
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			Dfs(arcs,n,i,visited);
			count_m++;
		}
	}
	printf("\n%d\n",count_m);
	return 0;
}
void Dfs(int arcs[MAX_SIZE][MAX_SIZE],int n,int i,int* visited){
	if(visited[i]==1)
	return;
	printf("%d ",i);
	visited[i]=1;
	for(int j=1;j<=n;j++){
		if(arcs[i][j]==1&&visited[j]==0){
			Dfs(arcs,n,j,visited);
		}
	}
}
