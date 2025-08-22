/*输入数据第一行为1个正整数n，表示关键字个数。第2行为n个整数表示n个关键字。
输出说明：
在一行上输出由关键字隐含的二叉树的后序遍历序列。
输入样例：
9
49 38 65 97 13 27 49 55 4
输出样例：
27 13 38 4 49 55 65 97 49*/
#include <iostream>
using namespace std;
const int MAX_SIZE=100;
void QuickSort(int* input,int left,int right);
int main(){
	int n;
	cin >> n;
	int input[MAX_SIZE];
	for(int i=0;i<n;i++){
		cin >> input[i];
	}
	QuickSort(input,0,n-1);
	return 0;
}
int PartSort(int* input,int left,int right){
	int key=input[left];
	//这里的快速排序必须是一找到目标元素就进行交换
	while(left<right){
		while(left<right&&input[right]>=key){
			right--;
		}
		input[left]=input[right];
		while(left<right&&input[left]<=key){
			left++;
		}
		input[right]=input[left];
	}
	input[right]=key;
	return right;
}
void QuickSort(int* input,int left,int right){
	if(left<=right){
		int key=PartSort(input,left,right);
		QuickSort(input,left,key-1);//打印左子树
		QuickSort(input,key+1,right);//打印右子树
		cout << input[key] << ' ';
	}
}
