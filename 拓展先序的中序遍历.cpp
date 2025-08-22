/*编一个程序，读入用户输入的一串扩展先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 例如如下的扩展先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。
输入格式
	输入包括1行字符串，长度不超过100。
输出格式
	输出将输入字符串建立二叉树后中序遍历的序列，每个字符后面都有一个空格。每个输出结果占一行。
样例输入
	abc##de#g##f###
样例输出
	c b e g d f a
样例说明
根据给定的扩展先序遍历序列，建立对应的二叉树，然后对所得的二叉树进行中序遍历输出结果即可。*/
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
