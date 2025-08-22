/*假设用于通信的电文由ｎ（4<n<30）个字符组成，字符在电文中出现的频度（权值）为w1w2…wn，试根据该权值序列构造哈夫曼树，并计算该树的带权路径长度。 
问题输入 
一组数据，第１行为ｎ的值，第２行为ｎ个整数，表示字符的出现频度。 
问题输出 
输出一个整数，表示所构造哈夫曼树的带权路径长度。 
输入样例 
8 
7  19  2  6  32  3  21  10
 
输出样例 
261 */
#include<stdio.h>
#include<stdlib.h>
#define MAXVALUE 1000
//哈夫曼树的存储结构
typedef struct HuffManTreeNode{
	int weight;
	int parent;
	int lchild,rchild;
}HuffManTreeNode,*HuffManTree;
void SelectHuffManTreeMinNode(HuffManTree huffManTree,int k,int* s1,int* s2);
int main(){
	int n;
	int s1,s2;
	int WPL=0;
	scanf("%d",&n);
	int m=2*n-1;//哈夫曼树的节点数目
	HuffManTree huffManTree=(HuffManTree)malloc((m+1)*sizeof(HuffManTreeNode));
	//对哈夫曼树进行初始化,注意为了方便，一般下标为0的节点不使用
	for(int i=1;i<=m;i++){
		huffManTree[i].parent=0;
		huffManTree[i].lchild=0;
		huffManTree[i].rchild=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&huffManTree[i].weight);
	}
	for(int i=n+1;i<=m;i++){
		SelectHuffManTreeMinNode(huffManTree,i-1,&s1,&s2);//从1到i-1中找到parent为0的所有节点的最小两个节点的下标
		huffManTree[i].lchild=s1;
		huffManTree[i].rchild=s2;
		huffManTree[s1].parent=i;
		huffManTree[s2].parent=i;
		huffManTree[i].weight=huffManTree[s1].weight+huffManTree[s2].weight;
	}
	for(int i=1;i<=n;i++){
		int len=0;//路径长度
		int p=i;
		while(huffManTree[p].parent!=0){
			len++;
			p=huffManTree[p].parent;
		}	
		WPL+=huffManTree[i].weight*len;
	}
	printf("%d",WPL);
	return 0;
}
void SelectHuffManTreeMinNode(HuffManTree huffManTree,int k,int* s1,int* s2){
	int min1=MAXVALUE;
	int min2=MAXVALUE;
	//两次for循环找到s1和s2对应的值
	for(int i=1;i<=k;i++){
		if(huffManTree[i].weight<min1&&huffManTree[i].parent==0){
			min1=huffManTree[i].weight;
			*s1 = i;
		}	
	}
	for(int i=1;i<=k;i++){
		if(huffManTree[i].weight<min2&&huffManTree[i].parent==0&& i != *s1){
			min2=huffManTree[i].weight;
			*s2 = i;
		}	
	}	
}
