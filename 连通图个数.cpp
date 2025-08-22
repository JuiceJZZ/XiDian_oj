#include<stdio.h>
#define MAX_SIZE 50 
void Dif(int arcs[MAX_SIZE][MAX_SIZE],int visited[MAX_SIZE],int n,int i,int* count);
void Sort(int count_v[MAX_SIZE],int n);
int main(){
	int arcs[MAX_SIZE][MAX_SIZE]={0};
	int i,j,k;
	int n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){//构造邻接矩阵
		scanf("%d%d",&j,&k);
		arcs[j][k]=arcs[k][j]=1;
	}
	int visited[MAX_SIZE]={0};
	int count_v[MAX_SIZE]={0};//存储最后连通图里的顶点数目
	int count_m=0;//计数连通图的个数,作为count_v的计数变量
	for(i=1;i<=n;i++){
		if(visited[i]==0){
			Dif(arcs,visited,n,i,&count_v[count_m]);
			count_m++;
		}
	}
	printf("%d\n",count_m);
	Sort(count_v,count_m);
	for(i=0;i<count_m;i++){
		printf("%d ",count_v[i]);
	}
	return 0;
}
void Dif(int arcs[MAX_SIZE][MAX_SIZE],int visited[MAX_SIZE],int n,int i,int* count){
	if(visited[i]==0){
		visited[i]=1;
		(*count)++;
		for(int j=1;j<=n;j++){
			if(arcs[i][j]==1){
				Dif(arcs,visited,n,j,count);
			}
		}
	}
}
void Sort(int count_v[MAX_SIZE],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(count_v[j]<count_v[i]){
				int tem=count_v[i];
				count_v[i]=count_v[j];
				count_v[j]=tem;
			}
		}
	}
}
