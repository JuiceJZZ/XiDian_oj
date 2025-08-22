/*第一行两个数n,root，分别表示二叉树有n个结点，第root个结点是二叉树的根。接下来共n行，第i行三个数val_i、left_i、right_i，分别表示第i个结点的值val是val_i，左儿子left是第left_i个结点，右儿子right是第right_i个结点。
节点0表示空。
1<=n<=100000,保证是合法的二叉树
输出格式
输出"true"如果给定二叉树是二叉排序树，否则输出"false"
样例输入
5 1
5 2 3
1 0 0
3 4 5
4 0 0
6 0 0
样例输出
false*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 100001
int k=0;
typedef struct BiTreeNode{
	int data;
	struct BiTreeNode* lchild,*rchild;
}BiTreeNode,*BiTree;
typedef struct NodeSet{
	int val;
	int leftIndex;
	int rightIndex;
}NodeSet;
BiTree CreatBiTree(int root,NodeSet* nodes);
void InOrderTraverse(BiTree tree,int* inOrder){
	if(tree){
		InOrderTraverse(tree->lchild,inOrder);
		inOrder[k++]=tree->data;
		InOrderTraverse(tree->rchild,inOrder);
	}
}
//二叉排序树的中序遍历一定是一个完全单调递增的序列
bool IsBSTree(int* inOrder){
	for (int i = 0; i < k - 1; i++) 
	{
		if (inOrder[i] >= inOrder[i + 1])
			return false;
	}
	return true;//我是张子佳，你好张子佳张子佳
}
int main(){
	int n,root;
	scanf("%d%d",&n,&root);
	NodeSet nodes[MAX_SIZE];
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&nodes[i].val,&nodes[i].leftIndex,&nodes[i].rightIndex);
	}
	BiTree tree=CreatBiTree(root,nodes);
	int inOrder[MAX_SIZE];
	InOrderTraverse(tree,inOrder);
	if(IsBSTree(inOrder))
	printf("true");
	else
	printf("false");
	return 0;
}
BiTree CreatBiTree(int root,NodeSet* nodes){
		BiTreeNode* tree=(BiTreeNode*)malloc(sizeof(BiTreeNode));
		tree->data=nodes[root].val;
		if(nodes[root].leftIndex==0)
		tree->lchild=NULL;
		else
		tree->lchild=CreatBiTree(nodes[root].leftIndex,nodes);
		if(nodes[root].rightIndex==0)
		tree->rchild=NULL;
		else
		tree->rchild=CreatBiTree(nodes[root].rightIndex,nodes);
		return tree;
}

