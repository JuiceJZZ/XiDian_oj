/*����
�ж��������Ƿ�Ϊͬһ�������������С�
�����ʽ
�����ж��顣ÿ�����ݵ�һ����һ����n��(1<=n<=20) ��ʾ��n����Ҫ�жϣ�
n=0 ��ʱ���������������ȥһ����һ�����У����г���С��10��
����(0~9)�����֣�û���ظ����֣�����������п��Թ����һ�Ŷ�����������
����ȥ��n����n�����У�ÿ�����и�ʽ����һ������һ����
���ж������������Ƿ������ͬһ�Ŷ�����������
�����ʽ
���������������ͬ�����YES���������NO
��������
2
567432
543267
576342
0
�������
YES
NO
����˵��
��*/
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
	//�ᱨ��
	//char* dd;
	//scanf("%s",dd);
	char d[20];  // ��һ���̶����ȵ��������洢������ַ���
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
