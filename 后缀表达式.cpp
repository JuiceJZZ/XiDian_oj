/*对逆波兰式（即后缀表达式）求值。其中每个操作数的取值范围为0~9，均为个位数。运算符为加减乘除四种（+、-、*、/）。如（4+5）*2-3的逆波兰式为45+2*3-。
输入说明：
一个字符串表示的逆波兰式，如：45+2*3-，表达式的长度不超过100。表达式均没有错误。
输出说明：
表达式的值。
输入样例：
45+2*3-
输出样例
15
提示
可采用栈为辅助存储结构，碰到操作数则入栈，碰到操作符则连续两次出栈，然后进行计算。*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 100
typedef struct Stack{
	int stack[MAX_SIZE];
	int top;
}Stack;
Stack* InitStack(){
	Stack* p=(Stack*)malloc(sizeof(Stack));
	p->top=-1;
	return p;
}
void Put(Stack* st,int data){
	st->stack[++st->top]=data;
}
bool IsEmpty(Stack* st){
	return st->top==-1;
}
int Pop(Stack*st){
	if(!IsEmpty(st))
	return st->stack[st->top--];
}
int StringToInt(char number){
	return number-'0';
}
bool IsNumber(char t){
	if(t>='0'&&t<='9')
	return true;
	else
	return false;
}
int main(){
	char in[MAX_SIZE];
	int m,t;
	scanf("%s",in);
	Stack* st=InitStack();
	int n=strlen(in);
	int res=0;//存储中间结果
	for(int i=0;i<n;i++){
		if(IsNumber(in[i])){
			int data=StringToInt(in[i]);
			Put(st,data);
		}
		else{
			switch(in[i]){
				case '+':
					res=Pop(st)+Pop(st);
					break;
				case '-':
					m=Pop(st);
					res=Pop(st)-m;
					break;
				case '*':
					res=Pop(st)*Pop(st);
					break;
				case '/':
					t=Pop(st);
					res=Pop(st)/t;
					break;
			}
			Put(st,res);
		}
	}
	printf("%d",Pop(st));
	return 0;
}
