/*输入一个整数组成的序列，然后将序列中的奇数位置结点依序放在前面，偶数位置结点依序放在后面，组成一个新的序列。输出此新序列。
问题输入
输入共两行，第一行是一个正整数n，表示序列长度，n<100。第二行是n个整数，中间用空格隔开，表示序列中的元素。
问题输出
在一行上输出新生成的序列，数字中间用空格隔开。
输入样例
7
10 2 30 4 50 60 7
输出样例
10 30 50 7 2 4 60*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList{
	int data;
	int order;
	struct LinkList* next;
}LinkList;
LinkList* InitLinkList(){
	LinkList* p=(LinkList*)malloc(sizeof(LinkList));
	p->next=NULL;
	return p;
}
LinkList* CreatLinkListNode(int data,int order){
	LinkList* p=(LinkList*)malloc(sizeof(LinkList));
	p->data=data;
	p->order=order;
	p->next=NULL;
	return p;
}
void CreatLinkList(LinkList* in,int n){
	LinkList* rear=in;
	for(int i=0;i<n;i++){
		int data,order;
		scanf("%d",&data);
		order=i+1;
		LinkList* p=CreatLinkListNode(data,order);
		rear->next=p;
		rear=p;
	}
}
int main(){
	LinkList* in=InitLinkList();
	int n;
	scanf("%d",&n);
	CreatLinkList(in,n);
	LinkList* oddlist=InitLinkList();
	LinkList* evenlist=InitLinkList();
	LinkList *oddrear,*evenrear;
	oddrear=oddlist;
	evenrear=evenlist;
	LinkList * rear=in->next;
	while(rear){
		if(rear->order%2==0){
			LinkList* p=CreatLinkListNode(rear->data,rear->order);
			evenrear->next=p;
			evenrear=p;
		}
		else{
			LinkList* p=CreatLinkListNode(rear->data,rear->order);
			oddrear->next=p;
			oddrear=p;
		}		
		rear=rear->next;
	}
	oddrear->next=evenlist->next;
	oddrear=oddlist->next;
	while(oddrear){
		printf("%d ",oddrear->data);
		oddrear=oddrear->next;
	}
	return 0;
}
