/*����һ��������ɵ����У�Ȼ�������е�����λ�ý���������ǰ�棬ż��λ�ý��������ں��棬���һ���µ����С�����������С�
��������
���빲���У���һ����һ��������n����ʾ���г��ȣ�n<100���ڶ�����n���������м��ÿո��������ʾ�����е�Ԫ�ء�
�������
��һ������������ɵ����У������м��ÿո������
��������
7
10 2 30 4 50 60 7
�������
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
