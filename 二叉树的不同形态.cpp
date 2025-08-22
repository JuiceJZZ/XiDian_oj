/*给定二叉树T（树深度H<=10，深度从1开始，结点个数N<1024，结点编号1~N）的层次遍历序列和中序遍历序列，输出T从左向右叶子结点以及二叉树先序和后序遍历序列。
输入格式
输入共三行：第一行是整数n，表示二叉树中的结点数目；第二行有n个整数，表示该二叉树的层次遍历序列；第三行也是n个整数，表示该二叉树的中序遍历序列。整数间以空格隔开。
输出格式
输出三行，分别是：从左向右的叶子结点，先序遍历序列，后序遍历序列。结点编号用空格隔开。
样例输入
7
3 5 4 2 6 7 1
2 5 3 6 4 7 1
样例输出
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
	for(int i=inl;i<=inr;i++){//寻找层序遍历里序号最小的为根节点
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
