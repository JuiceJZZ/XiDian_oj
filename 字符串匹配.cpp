/*编写程序：判断一个不大于 20 个字符的字符串是否是另一个不大于 20 个字符的字符串的子
串，如果是，则输出子串在父串的起始位置, 如果不是子串，则输出 No!。
输入说明
输入分 2 行：
第一行为主字符串；
第二行为子字符串；
输出说明
是子串，输出输出子串在父串的起始位置。
不是子串， 输出 No!*/
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 30
void GetNext(char* s2,int* next);
int IsMatch(char* s2,char* s1,int* next);
int main(){
	char s1[MAX_SIZE];//主串
	char s2[MAX_SIZE];//子串
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
			j=next[j];//当j回退到-1
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
