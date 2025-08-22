/*������һ������Ȼ����������飬���շ���ͳ�Ƴ��ִ�����������μ�������
�����ʽ
�����һ�б�ʾ������m������ÿ����������һ��Ϊ���ĸ���n��
���������зֱ���n��������һ����n������
�ڶ��е�n�����ֱ��Ӧ��һ��ÿ�����ķ��飬n������100��
���ͷ���ŵ�ֵ��������10000��
�����ʽ
��˳��������������Ľ���������ʽ�μ�����������Ŵ�С���������
��������Ҳ����Ŵ�С���������
��������
1
7
3 2 3 8 8 2 3
1 2 3 2 1 3 1
�������
1={2=0,3=2,8=1}
2={2=1,3=0,8=1}
3={2=1,3=1,8=0}*/
#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100
int hash[10000][100];//��ϣ���������洢����
int Count(int* groups,int n,int* g);
int CountValue(int* value,int n,int* v);
bool IsNotIn(int x,int* g,int k);
void Sort(int* g,int k);
void InitHash(int hash[10000][100],int n,int m);
int main(){
	int m;//�����������
	scanf("%d",&m);
	while(m--){
		InitHash(hash,10000,100);//ÿ�ε���hash��Ҫ��ʼ��
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
		int g[MAX_SIZE]={0};//������
		int v[MAX_SIZE]={0};//ֵ����
		int ng,nv;
		//ֻ�洢���ظ�ֵ��ȥ���ظ�
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











































