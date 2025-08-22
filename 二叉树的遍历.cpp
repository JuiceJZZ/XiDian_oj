/*给定一棵二叉树的先序遍历和中序遍历序列，求其后序遍历序列。
输入格式
	输入数据有两行，为两个字符串，其长度n均小于等于26。第一行为先序遍历序列，第二行为中序遍历序列。
二叉树中的结点名称以大写字母表示：A，B，C....最多26个结点。
输出格式
	在一行上输出后序遍历序列。
样例输入
ABC
BAC
样例输出
BCA*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct BiTreeNode{
	struct BiTreeNode* lchild;
	struct BiTreeNode* rchild;
	char data;
}BiTreeNode,*BiTree;
BiTreeNode* CreatBiTreeNode(char data){
	BiTreeNode* p=(BiTreeNode*)malloc(sizeof(BiTreeNode));
	p->data=data;
	return p;
}
#define MAX_SIZE 30
BiTree CreatBiTree(char* preTree,char* inTree,int pl,int pr,int il,int ir);
void PostOrderTraverse(BiTree tree);
int main(){
	char preTree[MAX_SIZE],inTree[MAX_SIZE];
	scanf("%s",preTree);
	scanf("%s",inTree);
	int len_pre=strlen(preTree);
	int len_in=strlen(inTree);
	BiTree tree=CreatBiTree(preTree,inTree,0,len_pre-1,0,len_in-1);
	PostOrderTraverse(tree);
	return 0;
}
BiTree CreatBiTree(char* preTree,char* inTree,int pl,int pr,int il,int ir){
	if(pl<=pr){
	BiTreeNode* t=CreatBiTreeNode(preTree[pl]);
	int k=il;
	while(preTree[pl]!=inTree[k])
	k++;
	t->lchild=CreatBiTree(preTree,inTree,pl+1,pl+k-il,il,k-1);
	t->rchild=CreatBiTree(preTree,inTree,pl+k-il+1,pr,k+1,ir);
	return t;
	}
	else 
	return NULL;
}
void PostOrderTraverse(BiTree tree){
	if(tree){
	PostOrderTraverse(tree->lchild);
	PostOrderTraverse(tree->rchild);
	printf("%c",tree->data);
	}
}

	
	
