/*��һ����ȫ�����������ĳһ��ȵ����нڵ㣬���������Щ�ڵ㣬�������EMPTY��
�����ʽ
	�����ж������ݡ�
ÿ�����ݵ�һ������һ�������n(1<=n<=1000)���ڶ��н����е���n���ڵ��������루ÿ�����洢��������һ�����֣���n������ŷ�ʽ�ǲ����ϵ��¡����ڴ��������α�ţ�����������һ��d������ȡ�
��n=0ʱ����ʾ���������
�����ʽ
	ÿ��������һ������������е�d������нڵ㣬�ڵ���ÿո������ÿ�����������ɺ�Ҫ���С�
��������
4
1 2 3 4
2
0
�������
2 3*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE 1001
int log(int n, int base){
    int i = 1, cnt = 0;
    while (i*base < n){
        i *= base;
        cnt++;
    }
    return cnt;
}
int main(){
	int n,d,complete_binary_tree[MAX_SIZE],group,j;
	int temp[100][100]={0};
	group=0;//���м���
	j=0;
	while(1){
		scanf("%d",&n);
		if(n==0)
		break;
		for(int i=1;i<=n;i++){//�ӵ�1����ʼʹ��
			scanf("%d",&complete_binary_tree[i]);
		}
		scanf("%d",&d);
		//��ʼ�������
		int k=log(n,2)+1;//������ȫ�����������
		if(d>k){
			group++;//��ʱû��Ԫ�أ�������һ��
		}
		else{
			int size=pow(2,d-1);//��d�㱾���е�Ԫ�ظ���
			int i=pow(2,d-1)-1;//��ʾ1��d-1���ȫ��Ԫ�ظ���
			for(i+=1;i<=n&&size>0;i++,size--){//��ȫ�������൱��ȫ����˳��洢�ģ�˳���Ҽ���
				temp[group][j]=complete_binary_tree[i];
				j++;  
			}
			j=0;
			group++;
		}
	}
	for(int i=0;i<group;i++){
		for(j=0;;j++){
			if(temp[i][0]==0){
				printf("EMPTY");
				break;
			}
			else{
			if(temp[i][j]==0){
				break;
			}
			printf("%d ",temp[i][j]);}
		}
		printf("\n");	
	}
	return 0;
}
