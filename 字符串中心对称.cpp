/*������n���ַ����ַ���������㷨�ж��ַ����Ƿ����ĶԳơ����磬xyzzyx��xyzyx�������ĶԳƵ��ַ�����
����˵����
ÿ��������2�У���һ��Ϊ����n����ʾ�ַ��ĸ�����nС��100���ڶ���Ϊn���ַ���ɵ��ַ�����
���˵����
�ж�����ַ����Ƿ������ĶԳƵģ��������YES�������������NO����
����������
12
ThanksThanks
���������
NO*/
#include<stdio.h>
#define MAXSIZE 1000
int main(){
	int n;
	scanf("%d",&n);
	char str[MAXSIZE]={0};
	scanf("%s",str);
	int j=n-1;
	int i=0;
	while(j>=i){
		if(str[j]!=str[i]){
			printf("NO");
			return -1;
		}
		j--;
		i++;
	}
	printf("YES");
	return 0;
}
