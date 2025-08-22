/*����һ�ö��������������������������У��������������С�
�����ʽ
	�������������У�Ϊ�����ַ������䳤��n��С�ڵ���26����һ��Ϊ����������У��ڶ���Ϊ����������С�
�������еĽ�������Դ�д��ĸ��ʾ��A��B��C....���26����㡣
�����ʽ
	��һ�����������������С�
��������
ABC
BAC
�������
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

	
	
