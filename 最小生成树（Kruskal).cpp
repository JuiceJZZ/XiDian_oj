/*�ÿ�³˹������Kruskal���㷨������������С��������
���룺
	�������ݵ�һ��Ϊ����������n��1<n<=30����m��1<m<100�����ֱ��ʾ�������ͱ������������m�����ݣ�ÿ��������һ���ߵ���Ϣ�������������֣��ֱ��ʾ�ñߵ���������ͱ��ϵ�Ȩֵ��
�����
	��˳�����Kruskal�㷨��õ���С�������ı߼���ÿ��һ���ߣ������������֣��ֱ��Ǹñߵ���������ͱ��ϵ�Ȩֵ�����е�һ������ı��ӦС�ڵڶ�������ı�š�
ʾ������
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
ʾ�����
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
	for(int i=0;i<m;i++){//����ߵ���Ϣ
		scanf("%d%d%d",&edgeSet[i].v1,&edgeSet[i].v2,&edgeSet[i].weight);
		if(edgeSet[i].v1>edgeSet[i].v2){
			int tem=edgeSet[i].v1;
			edgeSet[i].v1=edgeSet[i].v2;
			edgeSet[i].v2=tem;
		}
	}
	int vexSet[MAX_SIZE]={0};
	for(int i=1;i<=n;i++){//��ʼ�������������ͨ����
		vexSet[i]=i;
	}
	//�Ա߽��а���Ȩֵ��С�����������
	for(int i=0;i<m-1;i++){
		for(int j=i+1;j<m;j++){
			if(edgeSet[j].weight<edgeSet[i].weight){
				EdgeSet tem=edgeSet[i];
				edgeSet[i]=edgeSet[j];
				edgeSet[j]=tem;
			}
		}
	}
	int count=0;//��¼�Ѽ�����С�������ı���
	for(int i=0;i<m&&count<n-1;i++){
		if(vexSet[edgeSet[i].v1]!=vexSet[edgeSet[i].v2]){
			printf("%d %d %d\n",edgeSet[i].v1,edgeSet[i].v2,edgeSet[i].weight);
			count++;
			//��¼v1��v2���ڵ���ͨ����
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
