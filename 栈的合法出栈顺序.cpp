/*如果以序列“1,2,3,4”作为一个栈（初始为空）的输入，那么可得到输出序列“1,2,3,4”或“4,3,2,1”或“2,3,1,4”等等，但是肯定得不到输出序列“4,1,2,3”或“3,1,2,4”等等。请编写一个程序，判断能否通过一个栈得到给定的输出序列。
输入说明：
每组数据由两行构成，第一行只有一个整数n（<10），表示序列长度，同时表示栈的输入序列为“1,2,3,…,n”；第二行为n个整数，表示需要判断的出栈序列，整数之间以空格分隔。
输出说明：
输出一个yes或no（表示能否通过栈得到该序列）。
输入样例：
6
3 4 2 1 5 6
输出样例：
yes*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 20
typedef struct Stack{
	int stack[MAX_SIZE];
	int top;
}Stack;
Stack* InitStack(){
	Stack* p=(Stack*)malloc(sizeof(Stack));
	p->top=-1;
	return p;
}
bool IsEmpty(Stack* st){
	return st->top==-1;
}
void Pop(Stack* st){
	if(IsEmpty(st)){
		return;
	}
	else
	st->top--; 
}
void Put(Stack* st,int data){
	st->stack[++st->top]=data;
}
int Top(Stack* st){
	return st->stack[st->top];
}
int main(){
	int n;
	scanf("%d",&n);
	int in[MAX_SIZE]={0};
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	Stack* st=InitStack();//用于模拟栈的操作
	int j=0;//用于遍历in数组
	int i=1;
	while(true){
		if(IsEmpty(st)){
			Put(st,i);
			i++;
		}
		else{
			if(Top(st)!=in[j]){
				if(i!=n+1){//当i=n+1的时候已经没有元素可以入栈
				Put(st,i);
				i++;}
			}
			else{
				Pop(st);
				j++;
			}
		}
		//结束循环
		if(i==n+1){
			//所有元素都已经进入模拟栈里
			if(j==n){
				printf("yes");
				break;
			}
			else if(j!=n&&Top(st)!=in[j]){
				printf("no");
				break;
			}
		}
	}	
	return 0;	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
