#include<stdio.h>
#define MAXSIZE 1000
/*以二叉链表作为二叉树的存储结构*/
/*（1）统计二叉树的叶结点个数。*/
typedef struct TreeNode{
	int data;
	struct TreeNode* lchild,*rchild;	
}TreeNode,*BiTree;
int CountLeafNode(BiTree T){
	if(T==NULL)//空树
	return 0;
	else if(T->lchild==NULL&&T->rchild==NULL)//判断结点是否是叶子结点
	return 1;
	else
	return CountLeafNode(T->lchild)+CountLeafNode(T->rchild);
}
/*（3）交换二叉树每个结点的左孩子和右孩子。*/
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
}/*（5）计算二叉树最大的宽度（二叉树的最大宽度是指二叉树所有层中结点个数的最大值）。*/
//采用层次遍历的方法，记下各层结点数，每层遍历完毕，若结点数大于原先最大宽度，则修改最大宽度。
int TreeWidth(BiTree bt)//求二叉树bt的最大宽度
{
	if (bt==NULL) 
	return 0;  //空二叉树宽度为0
	else {
		BiTree Q[MAXSIZE];//Q是队列，元素为二叉树结点指针，容量足够大
		BiTree p;
		int front=1;//front队头指针,rear队尾指针,last同层最右结点在队列中的位置
		int rear=1;
		int last=1;
		int temp=0; //temp记局部宽度, maxw记最大宽度
		int maxw=0;  
		Q[rear]=bt;           //根结点入队列
		while(front<=last){
			p=Q[front++]; 
			temp++; //同层元素数加1
			if (p->lchild!=NULL)  
			Q[++rear]=p->lchild;   //左子女入队
			if (p->rchild!=NULL)  
			Q[++rear]=p->rchild;   //右子女入队
			if (front>last)      //一层结束， 
			{
				last=rear;
				if(temp>maxw) 
				maxw=temp;//last指向下层最右元素, 更新当前最大值
	     		temp=0;
 			}  
		}
return maxw;
}
/*（7）求任意二叉树中第一条最长的路径长度，并输出此路径上各结点的值。*/
void LongestPath(BiTree bt)//求二叉树中的第一条最长路径长度
{
	BiTree p=bt,l[MAXSIZE],s[MAXSIZE]; 
//l, s是栈，元素是二叉树结点指针，l中保留当前最长路径中的结点
int i=0,top=0,tag[MAXSIZE],longest=0;
while(p || top>0)
{
	while(p) {
		s[++top]=p;
		tag[top]=0;
		p=p->Lc;
		} //沿左分枝向下
	if(tag[top]==1)    //当前结点的右分枝已遍历
	{
		if(!s[top]->Lc && !s[top]->Rc){  //只有到叶子结点时，才查看路径长度
		if(top>longest) {
			for(i=1;i<=top;i++) 
			l[i]=s[i]; 
			longest=top; 
			top--;}
		}
//保留当前最长路径到l栈，记住最高栈顶指针，退栈
}
else if(top>0) 
{tag[top]=1; 
p=s[top].Rc;
}   //沿右子分枝向下
}
}
