/*��һ��������n,root���ֱ��ʾ��������n����㣬��root������Ƕ������ĸ�����������n�У���i��������val_i��left_i��right_i���ֱ��ʾ��i������ֵval��val_i�������left�ǵ�left_i����㣬�Ҷ���right�ǵ�right_i����㡣
�ڵ�0��ʾ�ա�
1<=n<=100000,��֤�ǺϷ��Ķ�����
�����ʽ
���"true"��������������Ƕ������������������"false"
��������
5 1
5 2 3
1 0 0
3 4 5
4 0 0
6 0 0
�������
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
//�������������������һ����һ����ȫ��������������
bool IsBSTree(int* inOrder){
	for (int i = 0; i < k - 1; i++) 
	{
		if (inOrder[i] >= inOrder[i + 1])
			return false;
	}
	return true;//�������Ӽѣ�������Ӽ����Ӽ�
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

