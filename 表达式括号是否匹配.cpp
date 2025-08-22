/*表达式中的合法括号为“(”、“)”、“[”、“]”、“{”、“}”，这三种括号可以按照任意的次序嵌套
使用。
请写一个程序，判断给定表达式中的括号是否匹配，既左右括号顺序和数量都匹配。
输入说明
输入为一个表达式字符串，长度不超过 50。
输出说明
对输入的表达式，若其中的括号是匹配的，则输出“yes”，否则输出“no”。
输入样例
样例 1 输入
[(d+f)*{}2]
样例 2 输入
[(2+3))
输出样例
样例 1 输出
yes
样例 2 输出
no*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 1000
typedef struct Stack{
	char sta[MAX_SIZE];
	int top;
}Stack;
bool IsStackEmpty(Stack* st){
	return st->top==-1;
}
void PopElement(Stack* st){
	if(IsStackEmpty(st))
	return;
	else
	st->top--;	
}
void PutElement(Stack* st,char data){
	st->sta[++st->top]=data;
}
Stack* CreatStack(){
	Stack* p=(Stack*)malloc(sizeof(Stack));
	p->top=-1;
	return p;
}
int main(){
	char s[MAX_SIZE];
	scanf("%s",s);
	Stack* st=CreatStack();
	int i=0;
	while(s[i]){
		if(s[i]=='('||s[i]=='['||s[i]=='{'){
			PutElement(st,s[i]);
		}
		if(s[i]==')'||s[i]==']'||s[i]=='}'){
			if(IsStackEmpty(st)){
				printf("no");
				return -1;
			}
			if(s[i]==')'){
				if(st->sta[st->top]=='('){
					PopElement(st);
				}
				else{
					printf("no");
					return -1;
				}
			}
			else if(s[i]==']'){
				if(st->sta[st->top]=='['){
					PopElement(st);
				}
				else{
					printf("no");
					return -1;
				}
			}			
			else{
				if(st->sta[st->top]=='{'){
					PopElement(st);
				}
				else{
					printf("no");
					return -1;
				}
			}					
		}
		i++;
	}
	if(IsStackEmpty(st))
	printf("yes");
	else
	printf("no");
	return 0;
}
