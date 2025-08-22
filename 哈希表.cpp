/*计算初始哈希值：首先根据关键字和除数 p 计算出初始的哈希值 hash_value = key % p。
检查初始位置：如果初始位置 table[hash_value] 为空（即 None），则将关键字插入该位置。
线性探测：如果初始位置已被占用，则从初始位置开始，依次检查后续位置，直到找到一个空闲位置为止。
循环处理：由于哈希表是环形结构，所以需要使用取模运算 (hash_value + i) % m 来确保索引在表长范围内循环。
插入关键字：一旦找到空闲位置，就将关键字插入该位置。*/
/*用除留余数法和线性探测再散列的冲突解决方法构造哈希表
输入：
	输入数据第一行为两个正整数分别为：哈希表表长m（m<100）和除数p（p<=m）。后面每一行是一个整数关键字，以-1作为输入的结束。
输出：
若输入的关键字在哈希表中已存在，则输出该关键字在哈希表中的位置，继续等待输入下一个关键字。
若输入的关键字在哈希表中不存在，则判断当前哈希表中关键字的个数是否等于m-1，若相等，
则输出“Table full”，程序结束；否则将关键字插入哈希表，
并输出该关键字插入在哈希表中的位置，继续等待输入下一个关键字。*/
#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 150
bool IsInHash(int* hash,int m,int x){
	for(int i=0;i<m;i++){
		if(hash[i]==x)
		return true;
	}
	return false;
}
int main(){
	int m,p;
	scanf("%d%d",&m,&p);
	int hash[MAX_SIZE];
	for(int i=0;i<MAX_SIZE;i++)
	hash[i]=-1;//由于-1是输入的结束标志，因此可以用来初始化hash数组，作为未使用的标志
	int input[MAX_SIZE];
	int i=0;
	int count=0;//用于记录hash表里现在放了多少个元素
	int key;
	while(true){
		scanf("%d",&input[i]);
		if(input[i]==-1){
			break;
		}
		if(!IsInHash(hash,m,input[i])){
			if(count==m-1){
				printf("Table full\n");
				break;
			}
	else{
			key=input[i]%p;
			while(hash[key]!=-1){
				key=(key+1)%m;
			}
			hash[key]=input[i];
			printf("%d\n",key);					
	}
	count++;	
}
		else{
			key=input[i]%p;
			//有可能当前的key的位置上已经被别的数字占据了，因此要线性探测
			while(hash[key]!=input[i]){
				key=(key+1)%m;
			}
			printf("%d\n",key);
		}
		i++;
	}
	return 0;
}


