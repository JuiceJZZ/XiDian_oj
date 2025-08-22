/*对给定的一个字符串，找出有重复的字符，并给出其位置。
输入格式
输入包括一个由字母和数字组成的字符串，其长度不超过100。
输出格式
可能有多组测试数据，对于每组数据，
按照样例输出的格式将字符出现的位置标出。

1、下标从0开始。
2、相同的字母在一行表示出其出现过的位置。
样例输入
样例输出
a:0,a:3,a:4,a:9
b:1,b:10
1:7,1:11
2:8,2:12
样例说明
给定字符串中重复的字母有a,b,1,2，依次输出上述每个字母在字符串中的全部位置。*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_SIZE 100
bool IsNotIn(char x,char* res,int k);
void abs(int index[MAX_SIZE][100],int i,char res,char* s);
int main(){
	char s[100];
	scanf("%s",s);
	char res[100];//记录那些有重复的字符
	int k=0;
	int n=strlen(s);
	int hash[200]={0};//用来统计每个字符出现的个数
	for(int i=0;i<n;i++){
		hash[s[i]]++;
	}
	//注意要按照题目的给定顺序输出，即每个字母的出现顺序
	for(int i=0;i<n;i++){
		if(hash[s[i]]>1&&IsNotIn(s[i],res,k)){
			res[k++]=s[i];
		}
	}
	int index[MAX_SIZE][100]={0};
	for(int i=0;i<k;i++){
		abs(index,i,res[i],s);
		for(int j=0;j<hash[res[i]]-1;j++){
			printf("%c:%d,",res[i],index[i][j]);
		}
		printf("%c:%d\n",res[i],index[i][hash[res[i]]-1]);
	}
	
	return 0;
}
bool IsNotIn(char x,char* res,int k){
	for(int i=0;i<k;i++){
		if(res[i]==x){
			return false;
		}
	}
	return true;
}
//在index的第i行记录字符res在s中出现的位置
void abs(int index[MAX_SIZE][100],int i,char res,char* s){
	int n=strlen(s);
	int k=0;
	for(int j=0;j<n;j++){
		if(s[j]==res){
			index[i][k++]=j;
		}
	}
}
