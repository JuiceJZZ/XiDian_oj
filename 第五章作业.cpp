#include<stdio.h>
#define MAXSIZE 1000
/*�Զ���������Ϊ�������Ĵ洢�ṹ*/
/*��1��ͳ�ƶ�������Ҷ��������*/
typedef struct TreeNode{
	int data;
	struct TreeNode* lchild,*rchild;	
}TreeNode,*BiTree;
int CountLeafNode(BiTree T){
	if(T==NULL)//����
	return 0;
	else if(T->lchild==NULL&&T->rchild==NULL)//�жϽ���Ƿ���Ҷ�ӽ��
	return 1;
	else
	return CountLeafNode(T->lchild)+CountLeafNode(T->rchild);
}
/*��3������������ÿ���������Ӻ��Һ��ӡ�*/
void ChangeLTreeRTree(BiTree &T){
	BiTree temp;
	if(T->lchild==NULL&&T->rchild==NULL)
	return;
	else{
		temp=T->lchild;
		T->lchild=T->rchild;
		T->rchild=temp;
	}
	ChangeLTreeRTree(T->lchild);
	ChangeLTreeRTree(T->rchild);
}/*��5��������������Ŀ�ȣ����������������ָ���������в��н����������ֵ����*/
//���ò�α����ķ��������¸���������ÿ�������ϣ������������ԭ������ȣ����޸�����ȡ�
int TreeWidth(BiTree bt)//�������bt�������
{
	if (bt==NULL) 
	return 0;  //�ն��������Ϊ0
	else {
		BiTree Q[MAXSIZE];//Q�Ƕ��У�Ԫ��Ϊ���������ָ�룬�����㹻��
		BiTree p;
		int front=1;//front��ͷָ��,rear��βָ��,lastͬ�����ҽ���ڶ����е�λ��
		int rear=1;
		int last=1;
		int temp=0; //temp�Ǿֲ����, maxw�������
		int maxw=0;  
		Q[rear]=bt;           //����������
		while(front<=last){
			p=Q[front++]; 
			temp++; //ͬ��Ԫ������1
			if (p->lchild!=NULL)  
			Q[++rear]=p->lchild;   //����Ů���
			if (p->rchild!=NULL)  
			Q[++rear]=p->rchild;   //����Ů���
			if (front>last)      //һ������� 
			{
				last=rear;
				if(temp>maxw) 
				maxw=temp;//lastָ���²�����Ԫ��, ���µ�ǰ���ֵ
	     		temp=0;
 			}  
		}
return maxw;
}
/*��7��������������е�һ�����·�����ȣ��������·���ϸ�����ֵ��*/
void LongestPath(BiTree bt)//��������еĵ�һ���·������
{
	BiTree p=bt,l[MAXSIZE],s[MAXSIZE]; 
//l, s��ջ��Ԫ���Ƕ��������ָ�룬l�б�����ǰ�·���еĽ��
int i=0,top=0,tag[MAXSIZE],longest=0;
while(p || top>0)
{
	while(p) {
		s[++top]=p;
		tag[top]=0;
		p=p->Lc;
		} //�����֦����
	if(tag[top]==1)    //��ǰ�����ҷ�֦�ѱ���
	{
		if(!s[top]->Lc && !s[top]->Rc){  //ֻ�е�Ҷ�ӽ��ʱ���Ų鿴·������
		if(top>longest) {
			for(i=1;i<=top;i++) 
			l[i]=s[i]; 
			longest=top; 
			top--;}
		}
//������ǰ�·����lջ����ס���ջ��ָ�룬��ջ
}
else if(top>0) 
{tag[top]=1; 
p=s[top].Rc;
}   //�����ӷ�֦����
}
}
