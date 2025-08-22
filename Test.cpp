#include<stdio.h>
#include<stdlib.h>
typedef struct Test{
	int data;
	struct Test* next;
}Test,*MyTest;
MyTest InitStack1(){
	MyTest p=(MyTest)malloc(sizeof(Test));
	p->next=NULL;
	return p;
}
void Push1(MyTest* S,int data){
	MyTest p=(MyTest)malloc(sizeof(Test));
	p->data=data;
	p->next=(*S);
	(*S)=p;
}
void Push2(MyTest S,int data){
	MyTest p=(MyTest)malloc(sizeof(Test));
	p->data=data;
	p->next=S;
	S=p;
}
void Pop(MyTest* S){
	MyTest p=(*S);
	*S=(*S)->next;
	free(p);
}
int main(){
	MyTest S1,S2;
	S1=InitStack1();
	S2=NULL;
	Push1(&S2,5);
	//Push2(S2,5);错误，不能实现压栈
	//Push2(S1,3);错误，不能实现压栈
	Push1(&S1,3);
	S1->next=NULL;
	Pop(&S1);
	return 0;
}
