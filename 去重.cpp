#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define ADDRESSLEN 6
#define MAXSIZE 1000
typedef struct Node{
	char preAddress[ADDRESSLEN];
	char rearAddress[ADDRESSLEN];
	int data;	
}Node;
typedef struct LinkList{
	Node base;
	struct LinkList* next;
	
}LinkList;
LinkList* InitLinkList();
LinkList* CreatLinkNode(Node data);
void PutInputIntoLinklist(LinkList* li,Node* input,int sum,char* firstAddress);
bool IsInResLink(LinkList* res,Node t);
void ProcessResult(LinkList* res,int sum);
int main(){
	int sum;
	char firstAddress[ADDRESSLEN];
	scanf("%s %d",firstAddress,&sum);
	Node input[MAXSIZE];
	for(int i=0;i<sum;i++){
		scanf("%s %d %s",input[i].preAddress,&input[i].data,input[i].rearAddress);
	}
	LinkList* li=InitLinkList();
	PutInputIntoLinklist(li,input,sum,firstAddress);
	
	LinkList* rear,*pre,*rear2;
	pre=li;
	rear=li->next;
	LinkList* res=InitLinkList();
	rear2=res;
	while(rear){
		if(IsInResLink(res,rear->base)){
			pre=rear;
			rear=rear->next;
			sum--;
		}
		else{
			LinkList* p=CreatLinkNode(rear->base);
			rear2->next=p;
			rear2=p;
			pre=rear;
			rear=rear->next;
		}
	}
	rear2=res->next;
	while(rear2){
			rear2=rear2->next;
		}
	ProcessResult(res,sum);
	rear2=res->next;
	
	printf("%d\n",sum);
	while(rear2){
		printf("%s %d %s\n",rear2->base.preAddress,rear2->base.data,rear2->base.rearAddress);
		rear2=rear2->next;
	}
	return 0;
}
LinkList* InitLinkList(){
	LinkList* li=(LinkList*)malloc(sizeof(LinkList));
	li->next=NULL;
	return li;
}
void PutInputIntoLinklist(LinkList* li,Node* input,int sum,char* firstAddress){
	LinkList* rear=li;
	int count=0;
	for(int i=0;i<sum;i++){
		if(strcmp(firstAddress,input[i].preAddress)==0){
			LinkList* p=CreatLinkNode(input[i]);
			rear->next=p;
			rear=p;
			count++;
			break;
		}
	}
	while(count<sum){
		for(int i=0;i<sum;i++){
			if(strcmp(rear->base.rearAddress,input[i].preAddress)==0){
				LinkList* p=CreatLinkNode(input[i]);
				rear->next=p;
				rear=p;
				count++;
				break;
			}
		}
	}
}
LinkList* CreatLinkNode(Node data){
	LinkList* p=(LinkList*)malloc(sizeof(LinkList));
	p->base=data;
	p->next=NULL;
	return p;
}
bool IsInResLink(LinkList* res,Node t){
	LinkList* rear=res;
	while(rear){
		if(abs(t.data)==abs(rear->base.data)){
			return true;
		}
		else{
			rear=rear->next;
		}
	}
	return false;
}
void ProcessResult(LinkList* res,int sum){
	if(sum==1){
		strcpy(res->next->base.rearAddress,"-1");
		return;
	}
	LinkList* rear,*pre;
	pre=res->next;
	rear=res->next->next;
	while(rear){
		strcpy(pre->base.rearAddress,rear->base.preAddress);
		pre=rear;
		rear=rear->next;
	}
	strcpy(pre->base.rearAddress,"-1");
	return;
}
