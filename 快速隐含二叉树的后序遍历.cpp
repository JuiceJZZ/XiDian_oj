/*�������ݵ�һ��Ϊ1��������n����ʾ�ؼ��ָ�������2��Ϊn��������ʾn���ؼ��֡�
���˵����
��һ��������ɹؼ��������Ķ������ĺ���������С�
����������
9
49 38 65 97 13 27 49 55 4
���������
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
	//����Ŀ������������һ�ҵ�Ŀ��Ԫ�ؾͽ��н���
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
		QuickSort(input,left,key-1);//��ӡ������
		QuickSort(input,key+1,right);//��ӡ������
		cout << input[key] << ' ';
	}
}
