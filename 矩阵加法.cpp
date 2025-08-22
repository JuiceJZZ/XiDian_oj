#include<stdio.h>
#define MAX_SIZE 100
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int matrix1[MAX_SIZE][MAX_SIZE],matrix2[MAX_SIZE][MAX_SIZE];
	int value1[MAX_SIZE],value2[MAX_SIZE];
	int n1=0,n2=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&matrix1[i][j]);
			if(matrix1[i][j]==1){
				n1++;//记录矩阵里有几个数字
			}
		}
	}
	for(int i=0;i<n1;i++){
		scanf("%d",&value1[i]);
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&matrix2[i][j]);
			if(matrix2[i][j]==1){
				n2++;//记录矩阵里有几个数字
			}
		}
	}
	for(int i=0;i<n2;i++){
		scanf("%d",&value2[i]);
	}	
	int matrix3[MAX_SIZE][MAX_SIZE]={0};
	int value3[MAX_SIZE]={0};
	int c=0;
	int a=0,b=0;//用于遍历value1和value2;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix1[i][j]==1&&matrix2[i][j]==0){
				matrix3[i][j]=1;
				value3[c++]=value1[a++];
			}
			if(matrix1[i][j]==0&&matrix2[i][j]==1){
				matrix3[i][j]=1;
				value3[c++]=value2[b++];
			}
			if(matrix1[i][j]==1&&matrix2[i][j]==1){
				if(value1[a]+value2[b]!=0){
					value3[c++]=value1[a++]+value2[b++];
					matrix3[i][j]=1;
				}
				else{
					a++;b++;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
				printf("%d ",matrix3[i][j]);
			}
			printf("\n");
		}
	
	
	for(int i=0;i<c;i++){
		printf("%d ",value3[i]);
	}	
	return 0;
}
