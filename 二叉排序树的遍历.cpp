/*输入一系列整数，建立二叉排序树，并进行前序，中序，后序遍历。
输入格式
输入第一行包括一个整数n(1<=n<=100)。
接下来的一行包括n个整数。
输出格式
将题目所给数据建立一个二叉排序树，并对二叉排序树进行前序、中序和后序遍历。
每种遍历结果输出一行。每行最后一个数据之后有一个空格。
输入中可能有重复元素，但是输出的二叉树遍历序列中重复元素不用输出。
样例输入
5
1 6 5 9 8
样例输出
1 6 5 9 8 
1 5 6 8 9 
5 8 9 6 1
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct BSTreeNode{
	int key;
	struct BSTreeNode *lchild,*rchild;
}BSTreeNode,*BSTree;
void InsertBSTree(BSTree* tree,int data){
	if(!(*tree)){
		BSTreeNode* node=(BSTreeNode*)malloc(sizeof(BSTreeNode));
		node->lchild=node->rchild=NULL;
		node->key=data;
		*tree=node;
	}	
	else{
		if(data==(*tree)->key){
			return;
		}
		else if(data<(*tree)->key){
			InsertBSTree(&((*tree)->lchild),data);
		}
		else{
			InsertBSTree(&((*tree)->rchild),data);
		}
	}
}
void CreatBSTree(BSTree* tree,int n){
	*tree=NULL;
	for(int i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		InsertBSTree(tree,data);
	}
}
void PreOrderTraverse(BSTree tree){
	if(tree){
		printf("%d ",tree->key);
		PreOrderTraverse(tree->lchild);
		PreOrderTraverse(tree->rchild);
	}
}
void InOrderTraverse(BSTree tree){
	if(tree){
		InOrderTraverse(tree->lchild);
		printf("%d ",tree->key);
		InOrderTraverse(tree->rchild);
	}
}
void PostOrderTraverse(BSTree tree){
	if(tree){
		PostOrderTraverse(tree->lchild);
		PostOrderTraverse(tree->rchild);
		printf("%d ",tree->key);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	BSTree tree=(BSTree)malloc(sizeof(BSTreeNode));
	CreatBSTree(&tree,n);
	PreOrderTraverse(tree);
	printf("\n");
	InOrderTraverse(tree);
	printf("\n");
	PostOrderTraverse(tree);
	printf("\n");
	return 0;
}

