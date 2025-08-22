/*所设计的程序能够通过编译。并能够实现从输入一个长度为n的顺序串str，并求出顺序串str的next值。
输入格式:
			首先输入串的长度n，然后输入顺序串str.
输出格式:
			输出str的next值，以空格分隔。
样例输入:
		8
		a b c a b c b c
样例输出:
		-1 0 0 0 1 2 3 0
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int main(){
	int n;
	scanf("%d\n",&n);
	char str[MAX_SIZE],s[MAX_SIZE];
	gets(s);
	int k=0;
	for(int i=0;i<2*n-1;i++){
		if(s[i]!=' '){
			str[k]=s[i];
			k++;
		}
	}
	int next[MAX_SIZE];
	next[0]=-1;
	next[1]=0;
	int i=1;
	int j=0;
	while(i<n){
		if(str[i]==str[j]||j==-1){
			j++;
			i++;
			next[i]=j;
		}
		else{
			j=next[j];
		}
	}
	for(int k=0;k<n;k++){
		printf("%d ",next[k]);
	}
	return 0;
}
