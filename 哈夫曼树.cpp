/*��������ͨ�ŵĵ����ɣ4<n<30�����ַ���ɣ��ַ��ڵ����г��ֵ�Ƶ�ȣ�Ȩֵ��Ϊw1w2��wn���Ը��ݸ�Ȩֵ���й����������������������Ĵ�Ȩ·�����ȡ� 
�������� 
һ�����ݣ��ڣ���Ϊ���ֵ���ڣ���Ϊ�����������ʾ�ַ��ĳ���Ƶ�ȡ� 
������� 
���һ����������ʾ��������������Ĵ�Ȩ·�����ȡ� 
�������� 
8 
7  19  2  6  32  3  21  10
 
������� 
261 */
#include<stdio.h>
#include<stdlib.h>
#define MAXVALUE 1000
//���������Ĵ洢�ṹ
typedef struct HuffManTreeNode{
	int weight;
	int parent;
	int lchild,rchild;
}HuffManTreeNode,*HuffManTree;
void SelectHuffManTreeMinNode(HuffManTree huffManTree,int k,int* s1,int* s2);
int main(){
	int n;
	int s1,s2;
	int WPL=0;
	scanf("%d",&n);
	int m=2*n-1;//���������Ľڵ���Ŀ
	HuffManTree huffManTree=(HuffManTree)malloc((m+1)*sizeof(HuffManTreeNode));
	//�Թ����������г�ʼ��,ע��Ϊ�˷��㣬һ���±�Ϊ0�Ľڵ㲻ʹ��
	for(int i=1;i<=m;i++){
		huffManTree[i].parent=0;
		huffManTree[i].lchild=0;
		huffManTree[i].rchild=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&huffManTree[i].weight);
	}
	for(int i=n+1;i<=m;i++){
		SelectHuffManTreeMinNode(huffManTree,i-1,&s1,&s2);//��1��i-1���ҵ�parentΪ0�����нڵ����С�����ڵ���±�
		huffManTree[i].lchild=s1;
		huffManTree[i].rchild=s2;
		huffManTree[s1].parent=i;
		huffManTree[s2].parent=i;
		huffManTree[i].weight=huffManTree[s1].weight+huffManTree[s2].weight;
	}
	for(int i=1;i<=n;i++){
		int len=0;//·������
		int p=i;
		while(huffManTree[p].parent!=0){
			len++;
			p=huffManTree[p].parent;
		}	
		WPL+=huffManTree[i].weight*len;
	}
	printf("%d",WPL);
	return 0;
}
void SelectHuffManTreeMinNode(HuffManTree huffManTree,int k,int* s1,int* s2){
	int min1=MAXVALUE;
	int min2=MAXVALUE;
	//����forѭ���ҵ�s1��s2��Ӧ��ֵ
	for(int i=1;i<=k;i++){
		if(huffManTree[i].weight<min1&&huffManTree[i].parent==0){
			min1=huffManTree[i].weight;
			*s1 = i;
		}	
	}
	for(int i=1;i<=k;i++){
		if(huffManTree[i].weight<min2&&huffManTree[i].parent==0&& i != *s1){
			min2=huffManTree[i].weight;
			*s2 = i;
		}	
	}	
}
