/*已知两个有序线性表L1和L2，每个线性表中数据元素的值为单调增的正整数（<100个），各线性表内部无重复元素。把L2中的元素合并到L1中，要求L1中数据元素的值仍为单调递增，且无重复元素。
问题输入 
第一行输入两个正整数a,b，分别表示第一个线性表L1和第二个线性表L2的长度；第2行依次输入L1中单调增的a个正整数；第3行依次输入L2中单调增的b个正整数。正整数均小于10000。
问题输出 
共有1行，最终合并并去重后的结果，每个数字之间有一个空格。
输入样例 
6 7
1 2 5 6 10 13
1 3 5 8 19 22 31
输出样例 
1 2 3 5 6 8 10 13 19 22 31*/
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList{
	int data;
	struct LinkList* next;
}LinkList;
LinkList* InitLinkList(){
	LinkList* p=(LinkList*)malloc(sizeof(LinkList));
	p->next=NULL;
	return p;
}
LinkList* CreatNode(int data){
	LinkList* p=(LinkList*)malloc(sizeof(LinkList));
	p->data=data;
	p->next=NULL;
	return p;
}
void CreatLinkList(LinkList* list,int num){
	LinkList* rear=list;
	for(int i=0;i<num;i++){
		int data;
		scanf("%d",&data);
		LinkList* t=CreatNode(data);
		rear->next=t;
		rear=t;
	}
}
void ProcessLinkList(LinkList* list3){
	LinkList* rear,*pre;
	pre=list3->next;
	rear=pre->next;
	while(rear){
		if(rear->data==pre->data){
			pre->next=rear->next;
			rear=rear->next;
		}
		else{
			pre=rear;
			rear=rear->next;
		}
	}
}
int main(){
	int numl1,numl2;
	scanf("%d %d",&numl1,&numl2);
	LinkList *list1,*list2;
	list1=InitLinkList();
	list2=InitLinkList();
	CreatLinkList(list1,numl1);
	CreatLinkList(list2,numl2);
	LinkList *rear1,*rear2;
	rear1=list1->next;
	rear2=list2->next;
	LinkList *list3,*rear3;
	if(rear1->data<rear2->data){
		list3=list1;
		rear3=rear1;
		rear1=rear1->next;
	}
	else{
		list3=list2;
		rear3=rear2;
		rear2=rear2->next;
	}
	while(rear1&&rear2){
		if(rear1->data<=rear2->data){
			rear3->next=rear1;
			rear3=rear3->next;
			rear1=rear1->next;
		}
		else{
			rear3->next=rear2;
			rear3=rear3->next;
			rear2=rear2->next;
		}
	}
	/*
	if(rear2){
		rear3->next=rear2;
	}
	else{
		rear3->next=rear1;
	}
	*/
	rear3->next=rear1?rear1:rear2;
	ProcessLinkList(list3);
	rear3=list3->next;
	while(rear3){
		printf("%d ",rear3->data);
		rear3=rear3->next;
	}
	return 0;
}
