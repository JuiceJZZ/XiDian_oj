/*����Ƶĳ����ܹ�ͨ�����롣���ܹ�ʵ�ִ�����һ������Ϊn��˳��str�������˳��str��nextֵ��
�����ʽ:
			�������봮�ĳ���n��Ȼ������˳��str.
�����ʽ:
			���str��nextֵ���Կո�ָ���
��������:
		8
		a b c a b c b c
�������:
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
