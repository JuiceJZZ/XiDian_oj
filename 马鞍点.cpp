/*����Ƶĳ����ܹ�ͨ�����롣������    �е�ĳ��Ԫ��    �ǵ�i���е���Сֵ��ͬʱ���ǵ�j���е����ֵ����ƴ�Ԫ��Ϊ�þ����е�һ�����㡣��д������������е��������㡣
�����ʽ
	����������������n��m��Ϊ����ά����Ȼ����������ֵ��
�����ʽ
	��������е��������㣬���˳���������ȣ����С�����ŵ���˳�������
    �����ж�����㣬ÿ������һ�С�Ҳ����û�����㣬�����NO��
��������
	4 4
2 7 9 10
1 0 7 12
8 23 13 15
4 6 12 18
�������
	3 1 8*/
#include<stdio.h>
#define MAX_SIZE 100
typedef struct MaAnNode{
	int i,j,data;
}MaAnNode;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int in[MAX_SIZE][MAX_SIZE];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&in[i][j]);
		}
	}
	MaAnNode res[MAX_SIZE];int q=0;
	int p;
	for(int i=0;i<n;i++){
		bool flag=true;
		int min=1000;
		for(int j=0;j<m;j++){
			if(in[i][j]<min){
				min=in[i][j];
				p=j;
			}
		}
		for(int k=0;k<n;k++){
			if(in[k][p]>in[i][p]){
				flag=false;
			}
		}
		if(flag){
			res[q++]={i,p,min};
		}
	}
	if(q==0){
		printf("No");
	}
	else{
		for(int i=0;i<q;i++){
			printf("%d %d %d\n",res[i].i+1,res[i].j+1,res[i].data);
		}
	}
	return 0;
}
