/*��һ����ȫ���������������϶��¡��������ҵķ�ʽ��1��ʼ��ţ�������֪��������������һ�������n�����ڵ��������Խ��mΪ��������һ���������ٸ���㣿
�����ʽ
	�������ݰ������У�ÿ�и���һ��������ݣ�������������m��n (1 <= m <= n <= 1000000000)��0 0��ʾ���������
�����ʽ
	����ÿһ��������ݣ����һ�У����а���һ�������������Խ��mΪ���������а����Ľ�����Ŀ��
��������
	3 12
    0 0
�������
	4*/
#include<stdio.h>
#define MAX_SIZE 100
void Count(int m,int n,int* count);
int main(){
	int n,m=1;
	int res[MAX_SIZE]={0};
	int i,j;
	i=0;
	while(1){
		int count=0;
		scanf("%d%d",&m,&n);
		if(m==0&&n==0)
		break;
		Count(m,n,&count);
		res[i]=count;
		i++;
	}
	for(j=0;j<i;j++){
		printf("%d\n",res[j]);
	}
	return 0;
}
void Count(int m,int n,int* count){
	if(m<=n)
	(*count)++;
	else 
	return;
	Count(2*m,n,count);
	Count(2*m+1,n,count);
}


