/*���ʽ�еĺϷ�����Ϊ��(������)������[������]������{������}�������������ſ��԰�������Ĵ���Ƕ��
ʹ�á�
��дһ�������жϸ������ʽ�е������Ƿ�ƥ�䣬����������˳���������ƥ�䡣
����˵��
����Ϊһ�����ʽ�ַ��������Ȳ����� 50��
���˵��
������ı��ʽ�������е�������ƥ��ģ��������yes�������������no����
��������
���� 1 ����
[(d+f)*{}2]
���� 2 ����
[(2+3))
�������
���� 1 ���
yes
���� 2 ���
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
