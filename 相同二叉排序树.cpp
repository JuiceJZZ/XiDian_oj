/*描述
判断两序列是否为同一二叉排序树序列。
输入格式
数据有多组。每组数据第一行是一个数n，(1<=n<=20) 表示有n个需要判断，
n=0 的时候输入结束。接下去一行是一个序列，序列长度小于10，
包含(0~9)的数字，没有重复数字，根据这个序列可以构造出一颗二叉排序树。
接下去的n行有n个序列，每个序列格式跟第一个序列一样，
请判断这两个序列是否能组成同一颗二叉排序树。
输出格式
如果二叉排序树相同则输出YES，否则输出NO
样例输入
2
567432
543267
576342
0
样例输出
YES
NO
样例说明
无*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct BSTreeNode{
	int data;
	struct BSTreeNode* lchild,*rchild;
}BSTreeNode,*BSTree;
void InsertBSTree(BSTree* tree,int data){
	if(!*tree){
		BSTree t=(BSTree)malloc(sizeof(BSTreeNode));
		t->data=data;
		t->lchild=t->rchild=NULL;
		*tree=t;
	}
	else if((*tree)->data<data){
		InsertBSTree(&((*tree)->rchild),data);
	}
	else{
		InsertBSTree(&((*tree)->lchild),data);
	}
}
void CreatBSTree(BSTree* tree){
	*tree=NULL;
	//会报错
	//char* dd;
	//scanf("%s",dd);
	char d[20];  // 用一个固定长度的数组来存储输入的字符串
	scanf("%s",d);
	int n = strlen(d);
	
	for(int i=0;i<n;i++){
		int data=d[i]-'0';
		InsertBSTree(tree,data);
	}	
}
bool IsEqual(BSTree T1, BSTree T2);
int main(){
	while(true){
		int n;
		scanf("%d",&n);
		if(n==0)
		break;
		BSTree given_tree;
		CreatBSTree(&given_tree);
		BSTree trees[20];
		for(int i=0;i<n;i++){
			CreatBSTree(&trees[i]);
		}
		for(int i=0;i<n;i++){
			if(IsEqual(given_tree,trees[i])){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
	}
	
	return 0;
}
bool IsEqual(BSTree T1, BSTree T2){
	if(T1==NULL&&T2==NULL){
		return true;
	}
	else if(T1==NULL||T2==NULL){
		return false;
	}
	else if(T1->data!=T2->data){
		return false;
	}
	else if(T1->data==T2->data){
		return IsEqual(T1->lchild, T2->lchild) && IsEqual(T1->rchild, T2->rchild);
	}	
}
