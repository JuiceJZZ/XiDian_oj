/*��Ŀ�� ����������֮�����
��������
����N���ؼ���ֵ������ͬ�Ľڵ㣬Ҫ���㰴˳�����һ����ʼΪ�����Ķ����������У�ÿ�β����ɹ�������Ӧ�ĸ��׽ڵ�Ĺؼ���ֵ�����û�и��׽ڵ㣬�����-1��
�����ʽ
�������������С���һ����һ������N��N<=100������ʾ������Ľڵ������ڶ�����N��������ͬ������������ʾҪ˳�����ڵ�Ĺؼ���ֵ����Щֵ������10^8��
�����ʽ
�����N�У�ÿ�β���ڵ������ýڵ��Ӧ�ĸ��׽ڵ�Ĺؼ���ֵ��
��������
5
2 5 1 3 4
�������
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
