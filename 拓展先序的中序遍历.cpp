/*��һ�����򣬶����û������һ����չ��������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� �������µ���չ��������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������
�����ʽ
	�������1���ַ��������Ȳ�����100��
�����ʽ
	����������ַ���������������������������У�ÿ���ַ����涼��һ���ո�ÿ��������ռһ�С�
��������
	abc##de#g##f###
�������
	c b e g d f a
����˵��
���ݸ�������չ����������У�������Ӧ�Ķ�������Ȼ������õĶ�������������������������ɡ�*/
#include<stdio.h>
#include<stdlib.h>
typedef struct BiTreeNode{
	struct BiTreeNode* lchild,*rchild;
	char data;
}BiTreeNode,*BiTree;
void CreatBiTree(BiTree* tree);
void InOrderTraverse(BiTree tree);
int main(){
	BiTree tree;
	CreatBiTree(&tree);
	InOrderTraverse(tree);
	return 0;
}
void CreatBiTree(BiTree* tree){
	//abc##de#g##f###
	char in;
	scanf("%c",&in);
	if(in=='#'){
		tree=NULL;
	}
	else{
		*tree=(BiTree)malloc(sizeof(BiTreeNode));
		(*tree)->data=in;
		(*tree)->lchild=NULL;
		(*tree)->rchild=NULL;
		CreatBiTree(&((*tree)->lchild));
		CreatBiTree(&((*tree)->rchild));
	}
}
void InOrderTraverse(BiTree tree){
	if(tree){
		InOrderTraverse(tree->lchild);
		printf("%c ",tree->data);
		InOrderTraverse(tree->rchild);
	}
}
