/*题目： 二叉排序树之父结点
问题描述
给你N个关键字值各不相同的节点，要求你按顺序插入一个初始为空树的二叉排序树中，每次插入后成功后，求相应的父亲节点的关键字值，如果没有父亲节点，则输出-1。
输入格式
测试数据有两行。第一行是一个数字N（N<=100），表示待插入的节点数。第二行是N个互不相同的正整数，表示要顺序插入节点的关键字值，这些值不超过10^8。
输出格式
输出共N行，每次插入节点后，输出该节点对应的父亲节点的关键字值。
样例输入
5
2 5 1 3 4
样例输出
-1
2
2
5
3*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct BSTreeNode{
	int key;
	struct BSTreeNode* lchild,*rchild;
}BSTreeNode,*BSTree;
void InsertBSTree(BSTree* tree,int data,int father){
	if(!(*tree)){
		BSTree t=(BSTree)malloc(sizeof(BSTreeNode));
		printf("%d\n",father);
		t->key=data;
		t->lchild=t->rchild=NULL;
		*tree=t;
	}
	else if((*tree)->key>data){
		InsertBSTree(&((*tree)->lchild),data,(*tree)->key);
	}
	else{
		InsertBSTree(&((*tree)->rchild),data,(*tree)->key);
	}
}
void CreatBSTree(BSTree* tree,int n){
	*tree=NULL;
	for(int i=0;i<n;i++){
		int data;
		scanf("%d",&data);
		InsertBSTree(tree,data,-1);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	BSTree tree=NULL;
	CreatBSTree(&tree,n);
	return 0;
}
