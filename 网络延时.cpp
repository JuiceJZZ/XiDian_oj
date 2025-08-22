/*��N������ڵ㣬���Ϊ1��N��
����һ����ά����times[M][3]����ʾ�źž�������ߵĴ���ʱ�䡣times[i][3] = {u, v, w}, ����u��Դ�ڵ㣬v��Ŀ��ڵ㣬
w��һ���źŴ�Դ�ڵ㴫�ݵ�Ŀ��ڵ��ʱ�䣬
����ά�����е�һ�б�ʾһ����Ȩ����ߡ�
���ڣ�������ǰ�Ľڵ�K ����һ���źš�
������Ҫ�೤ʱ�����ʹ���нڵ㶼�յ��źţ�
�������ʹ���нڵ��յ��źţ�����-1��
ע�⣺
1��M�ķ�Χ��[1,50]֮��
2��N�ķ�Χ��[1, 20] ֮�䡣
3��K�ķ�Χ��[1, N] ֮�䡣
4�����еı�times[i][3] =��u, v, w������1 <= u, v <= N �� 1 <= w <= 50��
�������� 
�����������ݣ���1��Ϊ3�����������ֱ���M��N��K����������M�У�ÿ����3�����������ֱ���u, v, w��
������� 
���һ��������ʾ��Ҫ��ò���ʹ���нڵ㶼�յ��źš��������ʹ���нڵ��յ��źţ�����-1
�������� 
3 4 2
2 1 1
2 3 1
3 4 1
������� 
2*/
/*Ӧ��ʹ��Dijkstra�㷨*/
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
	//��ʼ���ڽӾ���
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
	//��ʼ��D����
	for(int i=1;i<=n;i++){
		D[i]=arcs[k][i];
	}
	D[k]=0;
	int v;
	//������n-1������������μ���
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
