/*有N个网络节点，标记为1到N。
给定一个二维数组times[M][3]，表示信号经过有向边的传递时间。times[i][3] = {u, v, w}, 其中u是源节点，v是目标节点，
w是一个信号从源节点传递到目标节点的时间，
即二维数组中的一行表示一条带权有向边。
现在，我们向当前的节点K 发送一个信号。
最少需要多长时间才能使所有节点都收到信号？
如果不能使所有节点收到信号，返回-1。
注意：
1、M的范围在[1,50]之间
2、N的范围在[1, 20] 之间。
3、K的范围在[1, N] 之间。
4、所有的边times[i][3] =（u, v, w）都有1 <= u, v <= N 且 1 <= w <= 50。
问题输入 
多行输入数据，第1行为3个正整数，分别是M，N，K。接下来有M行，每行有3个正整数，分别是u, v, w。
问题输出 
输出一个数，表示需要多久才能使所有节点都收到信号。如果不能使所有节点收到信号，返回-1
输入样例 
3 4 2
2 1 1
2 3 1
3 4 1
输出样例 
2*/
/*应该使用Dijkstra算法*/
#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
const int MAX_VALUE=32767;
int MaxD(int* D,int n){
	int max=0;
	for(int i=1;i<=n;i++){
		if(D[i]>max&&D[i]!=MAX_VALUE){
			max=D[i];
		}
	}
	return max;
}
bool IsAllVisited(bool* S,int n){
	for(int i=1;i<=n;i++){
		if(S[i]==false)
		return false;
	}
	return true;	
}
int main(){
	int m,n,k;
	int arcs[MAX_SIZE][MAX_SIZE]={0};
	scanf("%d%d%d",&m,&n,&k);
	//初始化邻接矩阵
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arcs[i][j]=MAX_VALUE;
		}
	}
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		arcs[u][v]=w;
	}
	bool S[MAX_SIZE]={false};
	S[k]=true;
	int D[MAX_SIZE];
	//初始化D数组
	for(int i=1;i<=n;i++){
		D[i]=arcs[k][i];
	}
	D[k]=0;
	int v;
	//对其余n-1个顶点进行依次计算
	for(int i=1;i<n;i++){
		int min=MAX_VALUE;
		for(int j=1;j<=n;j++){
			if(!S[j]&&D[j]<min){
				v=j;min=D[j];
			}
		}
		S[v]=true;
			for(int j=1;j<=n;j++){
				if(!S[j]&&arcs[v][j]+D[v]<D[j]){
					D[j]=D[v]+arcs[v][j];
				}
			}
	}
	if(IsAllVisited(S,n)){
		printf("%d",MaxD(D,n));
	}
	else
	printf("-1");
	return 0;
}
