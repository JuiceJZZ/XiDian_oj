/*���������ĵ�1�и����������������ֱ��ǳ�����ĿN(<1000)�����и�����·��ĿM��
����M�ж�ӦM��������·��ÿ�и���һ����������
�ֱ��Ǹ���������·ֱ�����ӵ��������еı�š�Ϊ�������
���д�1��N��š�
���˵����
��һ����������ٻ���Ҫ���������������·��
����������
9 8
1 2
1 3
2 4
3 4
5 7
5 6
6 7
8 9
���������
2
ʵ����ʾ��
������ʵ��Ϊ����ͨ�����ĸ�����һ������������Ȼ�������������⣬Ҳ����MFSet��⡣*/
#include<stdio.h>
#define MAX_SIZE 1000
void Dfs(int arcSet[MAX_SIZE][MAX_SIZE],int n,int i,int* visited);
int main(){
	int arcSet[MAX_SIZE][MAX_SIZE]={0};
	int n,m;
	scanf("%d%d",&n,&m);
	int j,k;
	for(int i=0;i<m;i++){
		scanf("%d%d",&j,&k);
		arcSet[j][k]=arcSet[k][j]=1;
	}
	int count_m=0;
	int visited[MAX_SIZE]={0};
	for(int i=1;i<=n;i++){
		if(visited[i]==0){
			Dfs(arcSet,n,i,visited);
			count_m++;
		}
	}
	printf("%d",count_m-1);
	return 0;
}
void Dfs(int arcSet[MAX_SIZE][MAX_SIZE],int n,int i,int* visited){
	if(visited[i]==0){
		visited[i]=1;
		for(int j=1;j<=n;j++){
			if(arcSet[i][j]==1){
				Dfs(arcSet,n,j,visited);
			}
		}
	}
}
