/*��������С�1,2,3,4����Ϊһ��ջ����ʼΪ�գ������룬��ô�ɵõ�������С�1,2,3,4����4,3,2,1����2,3,1,4���ȵȣ����ǿ϶��ò���������С�4,1,2,3����3,1,2,4���ȵȡ����дһ�������ж��ܷ�ͨ��һ��ջ�õ�������������С�
����˵����
ÿ�����������й��ɣ���һ��ֻ��һ������n��<10������ʾ���г��ȣ�ͬʱ��ʾջ����������Ϊ��1,2,3,��,n�����ڶ���Ϊn����������ʾ��Ҫ�жϵĳ�ջ���У�����֮���Կո�ָ���
���˵����
���һ��yes��no����ʾ�ܷ�ͨ��ջ�õ������У���
����������
6
3 4 2 1 5 6
���������
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
	Stack* st=InitStack();//����ģ��ջ�Ĳ���
	int j=0;//���ڱ���in����
	int i=1;
	while(true){
		if(IsEmpty(st)){
			Put(st,i);
			i++;
		}
		else{
			if(Top(st)!=in[j]){
				if(i!=n+1){//��i=n+1��ʱ���Ѿ�û��Ԫ�ؿ�����ջ
				Put(st,i);
				i++;}
			}
			else{
				Pop(st);
				j++;
			}
		}
		//����ѭ��
		if(i==n+1){
			//����Ԫ�ض��Ѿ�����ģ��ջ��
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
