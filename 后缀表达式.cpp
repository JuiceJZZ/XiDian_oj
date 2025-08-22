/*���沨��ʽ������׺���ʽ����ֵ������ÿ����������ȡֵ��ΧΪ0~9����Ϊ��λ���������Ϊ�Ӽ��˳����֣�+��-��*��/�����磨4+5��*2-3���沨��ʽΪ45+2*3-��
����˵����
һ���ַ�����ʾ���沨��ʽ���磺45+2*3-�����ʽ�ĳ��Ȳ�����100�����ʽ��û�д���
���˵����
���ʽ��ֵ��
����������
45+2*3-
�������
15
��ʾ
�ɲ���ջΪ�����洢�ṹ����������������ջ���������������������γ�ջ��Ȼ����м��㡣*/
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
	int res=0;//�洢�м���
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
