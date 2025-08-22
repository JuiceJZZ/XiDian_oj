/*先输入一组数，然后输入其分组，按照分组统计出现次数并输出，参见样例。
输入格式
输入第一行表示样例数m，对于每个样例，第一行为数的个数n，
接下来两行分别有n个数，第一行有n个数，
第二行的n个数分别对应上一行每个数的分组，n不超过100。
数和分组号的值都不超过10000。
输出格式
按顺序输出各个样例的结果。输出格式参见样例，按组号从小到大输出，
组内数字也按编号从小到大输出。
样例输入
1
7
3 2 3 8 8 2 3
1 2 3 2 1 3 1
样例输出
1={2=0,3=2,8=1}
2={2=1,3=0,8=1}
3={2=1,3=1,8=0}*/
#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
int hash[10000][100];//哈希数组用来存储次数
int Count(int* groups,int n,int* g);
int CountValue(int* value,int n,int* v);
bool IsNotIn(int x,int* g,int k);
void Sort(int* g,int k);
void InitHash(int hash[10000][100],int n,int m);
int main(){
	int m;//几组测试数据
	scanf("%d",&m);
	while(m--){
		InitHash(hash,10000,100);//每次调用hash都要初始化
		int n;
		scanf("%d",&n);
		int value[MAX_SIZE];
		int groups[MAX_SIZE];
		for(int i=0;i<n;i++){
			scanf("%d",&value[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&groups[i]);
		}
		for(int i=0;i<n;i++){
			hash[groups[i]][value[i]]++;
		}
		int g[MAX_SIZE]={0};//组数组
		int v[MAX_SIZE]={0};//值数组
		int ng,nv;
		//只存储非重复值，去除重复
		ng=Count(groups,n,g);
		nv=Count(value,n,v);
		for(int i=0;i<ng;i++){
			printf("%d={",g[i]);
			for(int j=0;j<nv-1;j++){
				printf("%d=%d,",v[j],hash[g[i]][v[j]]);
			}
			printf("%d=%d}\n",v[nv-1],hash[g[i]][v[nv-1]]);
		}
	}	
	return 0;
}
int  Count(int* groups,int n,int* g){
	int k=0;
	for(int i=0;i<n;i++){
		if(IsNotIn(groups[i],g,k)){
			g[k++]=groups[i];
		}
	}
	Sort(g,k);
	return k;
}
bool IsNotIn(int x,int* g,int k){
	for(int i=0;i<k;i++){
		if(g[i]==x)
		return false;
	}
	return true;
}
void Sort(int* g,int k){
	for(int i=0;i<k-1;i++){
		for(int j=i+1;j<k;j++){
			if(g[j]<g[i]){
				int t=g[j];
				g[j]=g[i];
				g[i]=t;
			}
		}
	}
}
void InitHash(int hash[10000][100],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			hash[i][j]=0;
		}
	}
}











































