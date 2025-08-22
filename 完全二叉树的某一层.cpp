/*对一棵完全二叉树，输出某一深度的所有节点，有则输出这些节点，无则输出EMPTY。
输入格式
	输入有多组数据。
每组数据第一行输入一个结点数n(1<=n<=1000)，第二行将树中的这n个节点依次输入（每个结点存储的数据是一个数字），n个结点编号方式是层间从上到下、层内从左到右依次编号；第三行输入一个d代表深度。
当n=0时，表示输入结束。
输出格式
	每组数据在一行上输出该树中第d层的所有节点，节点间用空格隔开。每组数据输出完成后要换行。
样例输入
4
1 2 3 4
2
0
样例输出
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
	group=0;//共有几组
	j=0;
	while(1){
		scanf("%d",&n);
		if(n==0)
		break;
		for(int i=1;i<=n;i++){//从第1个开始使用
			scanf("%d",&complete_binary_tree[i]);
		}
		scanf("%d",&d);
		//开始处理并输出
		int k=log(n,2)+1;//代表完全二叉树的深度
		if(d>k){
			group++;//此时没有元素，跳过这一组
		}
		else{
			int size=pow(2,d-1);//第d层本该有的元素个数
			int i=pow(2,d-1)-1;//表示1到d-1层的全部元素个数
			for(i+=1;i<=n&&size>0;i++,size--){//完全二叉树相当于全部是顺序存储的，顺着找即可
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
