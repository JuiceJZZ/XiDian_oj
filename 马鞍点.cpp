/*所设计的程序能够通过编译。若矩阵    中的某个元素    是第i行中的最小值，同时又是第j列中的最大值，则称此元素为该矩阵中的一个马鞍点。编写程序求出矩阵中的所有马鞍点。
输入格式
	首先输入两个整数n和m，为矩阵维数，然后输入矩阵的值。
输出格式
	输出矩阵中的所有马鞍点，输出顺序：行序优先，按行、列序号递增顺序输出。
    ，若有多个马鞍点，每个马鞍点一行。也可能没有马鞍点，则输出NO。
样例输入
	4 4
2 7 9 10
1 0 7 12
8 23 13 15
4 6 12 18
样例输出
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
