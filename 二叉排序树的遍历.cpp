/*����һϵ������������������������������ǰ�����򣬺��������
�����ʽ
�����һ�а���һ������n(1<=n<=100)��
��������һ�а���n��������
�����ʽ
����Ŀ�������ݽ���һ�����������������Զ�������������ǰ������ͺ��������
ÿ�ֱ���������һ�С�ÿ�����һ������֮����һ���ո�
�����п������ظ�Ԫ�أ���������Ķ����������������ظ�Ԫ�ز��������
��������
5
1 6 5 9 8
�������
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

