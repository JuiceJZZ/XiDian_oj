/*��д�����ж�һ�������� 20 ���ַ����ַ����Ƿ�����һ�������� 20 ���ַ����ַ�������
��������ǣ�������Ӵ��ڸ�������ʼλ��, ��������Ӵ�������� No!��
����˵��
����� 2 �У�
��һ��Ϊ���ַ�����
�ڶ���Ϊ���ַ�����
���˵��
���Ӵ����������Ӵ��ڸ�������ʼλ�á�
�����Ӵ��� ��� No!*/
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 30
void GetNext(char* s2,int* next);
int IsMatch(char* s2,char* s1,int* next);
int main(){
	char s1[MAX_SIZE];//����
	char s2[MAX_SIZE];//�Ӵ�
	int next[MAX_SIZE]={0};
	gets(s1);
	gets(s2);
	GetNext(s2,next);
	if(IsMatch(s2,s1,next)==-1){
		printf("No!");
	}
	else{
		printf("%d",IsMatch(s2,s1,next)+1);
	}
	return 0;
}
void GetNext(char* s2,int* next){
	next[0]=-1;
	next[1]=0;
	int i=1,j=0;
	while(i<strlen(s2)){
		if(s2[i]==s2[j]||j==-1){
			i++;
			j++;
			next[i]=j;
		}
		else{
			j=next[j];//��j���˵�-1
		}
	}
}
int IsMatch(char* s2,char* s1,int* next){
	int i=0,j=0;
	int n1=strlen(s1);
	int n2=strlen(s2);
	while(i<n1&&j<n2){
		if(j==-1||s1[i]==s2[j]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j==n2){
		return i-n2;
	}
	return -1;
}
