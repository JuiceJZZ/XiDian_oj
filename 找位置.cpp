/*�Ը�����һ���ַ������ҳ����ظ����ַ�����������λ�á�
�����ʽ
�������һ������ĸ��������ɵ��ַ������䳤�Ȳ�����100��
�����ʽ
�����ж���������ݣ�����ÿ�����ݣ�
������������ĸ�ʽ���ַ����ֵ�λ�ñ����

1���±��0��ʼ��
2����ͬ����ĸ��һ�б�ʾ������ֹ���λ�á�
��������
�������
a:0,a:3,a:4,a:9
b:1,b:10
1:7,1:11
2:8,2:12
����˵��
�����ַ������ظ�����ĸ��a,b,1,2�������������ÿ����ĸ���ַ����е�ȫ��λ�á�*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_SIZE 100
bool IsNotIn(char x,char* res,int k);
void abs(int index[MAX_SIZE][100],int i,char res,char* s);
int main(){
	char s[100];
	scanf("%s",s);
	char res[100];//��¼��Щ���ظ����ַ�
	int k=0;
	int n=strlen(s);
	int hash[200]={0};//����ͳ��ÿ���ַ����ֵĸ���
	for(int i=0;i<n;i++){
		hash[s[i]]++;
	}
	//ע��Ҫ������Ŀ�ĸ���˳���������ÿ����ĸ�ĳ���˳��
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
//��index�ĵ�i�м�¼�ַ�res��s�г��ֵ�λ��
void abs(int index[MAX_SIZE][100],int i,char res,char* s){
	int n=strlen(s);
	int k=0;
	for(int j=0;j<n;j++){
		if(s[j]==res){
			index[i][k++]=j;
		}
	}
}
