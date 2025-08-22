/*测试用例的第1行给出两个正整数，分别是城市数目N(<1000)和现有高铁线路数目M。
随后的M行对应M条高铁线路，每行给出一对正整数，
分别是该条高铁线路直接连接的两个城市的编号。为简单起见，
城市从1到N编号。
输出说明：
在一行上输出最少还需要建设多少条高铁线路。
输入样例：
9 8
1 2
1 3
2 4
3 4
5 7
5 6
6 7
8 9
输出样例：
2
实现提示：
该问题实质为求连通分量的个数减一，可用深度优先或广度优先搜索求解，也可用MFSet求解。*/
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
