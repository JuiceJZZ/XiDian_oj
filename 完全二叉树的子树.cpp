/*对一棵完全二叉树，采用自上而下、自左往右的方式从1开始编号，我们已知这个二叉树的最后一个结点是n，现在的问题是以结点m为根的子树一共包括多少个结点？
输入格式
	输入数据包括多行，每行给出一组测试数据，包括两个整数m，n (1 <= m <= n <= 1000000000)。0 0表示输入结束。
输出格式
	对于每一组测试数据，输出一行，该行包含一个整数，给出以结点m为根的子树中包括的结点的数目。
样例输入
	3 12
    0 0
样例输出
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


