/*����������T�������H<=10����ȴ�1��ʼ��������N<1024�������1~N���Ĳ�α������к�����������У����T��������Ҷ�ӽ���Լ�����������ͺ���������С�
�����ʽ
���빲���У���һ��������n����ʾ�������еĽ����Ŀ���ڶ�����n����������ʾ�ö������Ĳ�α������У�������Ҳ��n����������ʾ�ö�����������������С��������Կո������
�����ʽ
������У��ֱ��ǣ��������ҵ�Ҷ�ӽ�㣬����������У�����������С�������ÿո������
��������
7
3 5 4 2 6 7 1
2 5 3 6 4 7 1
�������
2 6 1
3 5 2 4 6 7 1
2 5 6 1 7 4 3*/
#include<stdio.h>
#include<stdlib.h>
typedef struct BiTreeNode{
	struct BiTreeNode* lchild;
	struct BiTreeNode* rchild;
	int data;
}BiTreeNode,*BiTree;
#define MAX_SIZE 1024
BiTree 	CreatBiTree(int* in,int* mapLayer,int inl,int inr);
void LeaveTraverse(BiTree tree);
void PreOrderTraverse(BiTree tree);
void PostOrderTraverse(BiTree tree);
int main(){
	int n;
	scanf("%d",&n);
	int layer[MAX_SIZE];
	int in[MAX_SIZE];
	for(int i=0;i<n;i++){
		scanf("%d",&layer[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}	
	int mapLayer[MAX_SIZE];
	for(int i=0;i<n;i++){
		mapLayer[layer[i]]=i;
	}
	BiTree tree=CreatBiTree(in,mapLayer,0,n-1);
	LeaveTraverse(tree);
	printf("\n");
	PreOrderTraverse(tree);
	printf("\n");
	PostOrderTraverse(tree);
	return 0;
}
BiTree 	CreatBiTree(int* in,int* mapLayer,int inl,int inr){
	if(inl>inr)
	return NULL;
	int rootPos=inl;
	for(int i=inl;i<=inr;i++){//Ѱ�Ҳ�������������С��Ϊ���ڵ�
		if(mapLayer[in[i]]<mapLayer[in[rootPos]])
			rootPos=i;
	}
	BiTree tree=(BiTree)malloc(sizeof(BiTreeNode));
	tree->data=in[rootPos];
	tree->lchild=CreatBiTree(in,mapLayer,inl,rootPos-1);
	tree->rchild=CreatBiTree(in,mapLayer,rootPos+1,inr);
	return tree;
}
void LeaveTraverse(BiTree tree){
	if(tree){
		if(tree->rchild==NULL&&tree->lchild==NULL){
			printf("%d ",tree->data);
		}
		LeaveTraverse(tree->lchild);
		LeaveTraverse(tree->rchild);
	}
}
void PreOrderTraverse(BiTree tree){
	if(tree){
		printf("%d ",tree->data);
		PreOrderTraverse(tree->lchild);
		PreOrderTraverse(tree->rchild);
	}
}
void PostOrderTraverse(BiTree tree){
	if(tree){
		PostOrderTraverse(tree->lchild);
		PostOrderTraverse(tree->rchild);
		printf("%d ",tree->data);
	}	
}
