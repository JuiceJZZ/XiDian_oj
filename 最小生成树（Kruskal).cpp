/*用克鲁斯卡尔（Kruskal）算法求无向网的最小生成树。
输入：
	输入数据第一行为两个正整数n（1<n<=30）和m（1<m<100），分别表示顶点数和边数。后面紧跟m行数据，每行数据是一条边的信息，包括三个数字，分别表示该边的两个顶点和边上的权值。
输出：
	按顺序输出Kruskal算法求得的最小生成树的边集，每行一条边，包括三个数字，分别是该边的两个顶点和边上的权值，其中第一个顶点的编号应小于第二个顶点的编号。
示例输入
8 11
1 2 3
1 4 5
1 6 18
2 4 7
2 5 6
3 5 10
3 8 20
4 6 15
4 7 11
5 7 8
5 8 12
示例输出
1 2 3
1 4 5
2 5 6
5 7 8
3 5 10
5 8 12
4 6 15*/
#include<stdio.h>
typedef struct EdgeSet{
	int v1,v2;
	int weight;
}EdgeSet;
#define MAX_SIZE 100
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	EdgeSet edgeSet[MAX_SIZE];
	for(int i=0;i<m;i++){//输入边的信息
		scanf("%d%d%d",&edgeSet[i].v1,&edgeSet[i].v2,&edgeSet[i].weight);
		if(edgeSet[i].v1>edgeSet[i].v2){
			int tem=edgeSet[i].v1;
			edgeSet[i].v1=edgeSet[i].v2;
			edgeSet[i].v2=tem;
		}
	}
	int vexSet[MAX_SIZE]={0};
	for(int i=1;i<=n;i++){//初始化各个顶点的连通分量
		vexSet[i]=i;
	}
	//对边进行按照权值从小到大进行排序
	for(int i=0;i<m-1;i++){
		for(int j=i+1;j<m;j++){
			if(edgeSet[j].weight<edgeSet[i].weight){
				EdgeSet tem=edgeSet[i];
				edgeSet[i]=edgeSet[j];
				edgeSet[j]=tem;
			}
		}
	}
	int count=0;//记录已加入最小生成树的边数
	for(int i=0;i<m&&count<n-1;i++){
		if(vexSet[edgeSet[i].v1]!=vexSet[edgeSet[i].v2]){
			printf("%d %d %d\n",edgeSet[i].v1,edgeSet[i].v2,edgeSet[i].weight);
			count++;
			//记录v1和v2所在的连通分量
			int vs1=vexSet[edgeSet[i].v1];
			int vs2=vexSet[edgeSet[i].v2];
			for(int j=1;j<=n;j++){
				if(vexSet[j]==vs2){
					vexSet[j]=vs1;
				}
			}
		}
	}
	return 0;
}
