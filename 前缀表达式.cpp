/*对前缀表达式求值，其中操作数为正整数，运算符只包含+-，运算结果也为整数。如(42+8)*(36-6)+9/3的前缀表达式为：+ * + 42 8 – 36 6 / 9 3。
输入说明：
	输入为一行，一个字符串表示的前缀表达式，如：+ * + 42 8 – 36 6 / 9 3，表达式的长度不超过100，式中不同元素之间用空格隔开。
输出说明：
输出表达式的值（这里只考虑计算结果为整数的情况）。
输入样例：
+ * + 42 8 – 36 6 / 9 3
输出样例
1503*/
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
int Factorial(int grade){
	int t=1;
	for(int i=1;i<=grade-1;i++){
		t*=10;
	}
	return t;
}
int main(){
	char in[MAX_SIZE];
	gets(in);
	int n=strlen(in);
	Stack* st=InitStack();
	int res=0;
	int t,m;
	for(int i=n-1;i>=0;i--){
		if(IsNumber(in[i])){
			int process=0;
			int j=i-1;
			int grade=1;//10的级数
			process+=StringToInt(in[i])*Factorial(grade);
			while(in[j]!=' '){
				grade++;
				process+=StringToInt(in[j])*Factorial(grade);
				j--;
			}
			Put(st,process);
			i=j;
		}
		else if(in[i]==' '){
			continue;
		}
		else if(!IsNumber(in[i])){
			switch(in[i]){
				case '+':
					res=Pop(st)+Pop(st);
					break;
				case '-':
					m=Pop(st);
					res=m-Pop(st);
					break;
				case '*':
					res=Pop(st)*Pop(st);
					break;
				case '/':
					t=Pop(st);
					res=t/Pop(st);
					break;
			}
			Put(st,res);			
		}
	}
	printf("%d",Pop(st));
	return 0;
}
