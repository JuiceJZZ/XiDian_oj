/*二叉树给出先序和中序遍历序列，求和树要求输出中序遍历序列；
所有处理数据不会大于int类型范围。
输入格式
输入共3行：第一行为满二叉树中结点个数n（n<1024）；第二行为n个整数，表示二叉树的先序遍历序列；第三行也有n个整数，表示二叉树的中序遍历序列。整数间以空格分割。
输出格式
输出1行整数，表示求和树的中序遍历序列。整数间以空格分割。
样例输入
7
10 -2 8 -4 6 7 5
8 -2 -4 10 7 6 5
样例输出
0 4 0 20 0 12 0*/
#include<stdio.h>
#include<stdlib.h>
typedef struct BiTreeNode{
	struct BiTreeNode *lchild,*rchild;
	int data;
}BiTreeNode,*BiTree;
BiTree CreatBiTree(int* pre,int* in,int pl,int pr,int il,int ir);
void InOrderTraverse(BiTree sumTree);
#define MAX_SIZE 1024
int main(){
	int n;
	scanf("%d",&n);
	int pre[MAX_SIZE],in[MAX_SIZE];
	for(int i=0;i<n;i++){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}	
	BiTree sumTree=CreatBiTree(pre,in,0,n-1,0,n-1);
	InOrderTraverse(sumTree);
	return 0;
}
BiTree CreatBiTree(int* pre,int* in,int pl,int pr,int il,int ir){
	if(pl>pr)
	return NULL;
	BiTree tree=(BiTree)malloc(sizeof(BiTreeNode));
	int k=il;
	while(in[k]!=pre[pl])
	k++;
	int data=0;
	for(int i=il;i<=ir;i++){
		if(i!=k){//中序遍历序列中去除根节点就是左右子树
			data+=in[i];
		}
	}
	tree->data=data;
	tree->lchild=CreatBiTree(pre,in,pl+1,pl+k-il,il,k-1);
	tree->rchild=CreatBiTree(pre,in,pl+1+k-il,pr,k+1,ir);
	return tree;
}
void InOrderTraverse(BiTree sumTree){
	if(sumTree){
		InOrderTraverse(sumTree->lchild);
		printf("%d ",sumTree->data);
		InOrderTraverse(sumTree->rchild);
	}
}
