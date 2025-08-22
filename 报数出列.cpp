/*已知N个人（以编号1，2，3，...，N分别表示）排成一列, 第一轮从编号为1的人开始依次报数，数到2的倍数的人出列；第二轮从头开始依次报数，数到3的倍数的人出列；第三轮再次从头开始依次报数，数到2的倍数的人出列；第四轮从头开始依次报数，数到3的倍数的人出列；依此规律重复下去，直到队列中的人数不超过三个为止。要求输出此时队列中剩下的人在初始队列中的编号。
问题输入 
一个正整数N，表示初始人数，N≤5000。
问题输出 
输出队列中剩下的人在初始队列中的编号，编号之间有一个空格。
输入样例 
20
输出样例 
1 7 19
提示
可以使用队列，每次操作时对队列中元素进行判断，不需要舍弃的就重新加入队列；*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Queue{
	int data;
	struct Queue* next;
}Queue;
Queue* CreatQueueNode(int data){
	Queue* node=(Queue*)malloc(sizeof(Queue));
	node->data=data;
	node->next=NULL;
	return node;
}
Queue* PutElement(Queue* que,int n){
	Queue* rear=que;
	for(int i=0;i<n;i++){
		int data=i+1;
		Queue* t=CreatQueueNode(data);
		rear->next=t;
		rear=t;
	}
	return rear;
}
int main(){
	int n;
	scanf("%d",&n);
	Queue* que=(Queue*)malloc(sizeof(Queue));
	que->next=NULL;
	Queue* front,*rear,*newrear;
	newrear=rear=PutElement(que,n);
	front=que->next;
	int flag=2;//标志是2的倍数还是3的倍数
	int count=1;//报数变量
	if(n<=3){
		while(front!=rear){
				printf("%d ",front->data);
				front=front->next;
			}
			printf("%d",front->data);
			return -1;
	}
	while(n>3){
		if(flag==2){
			while(1){
				if(front==rear){
					if(count%2!=0){
						newrear->next=front;
						newrear=newrear->next;
						front=front->next;
						rear=newrear;
						flag=3;
						count=1;
						break;
					}
					else{
							n--;
							front=front->next;
							rear=newrear;
							flag=3;
							count=1;
							break;
						}
				}
				else{
				if(count%2!=0){
					newrear->next=front;
					newrear=newrear->next;
					front=front->next;
					count++;
				}
				else{
					n--;
					front=front->next;
					count++;
				}
			}
			}
		}
		else{
			while(1){
				if(front==rear){
					if(count%3!=0){
						newrear->next=front;
						newrear=newrear->next;
						front=front->next;
						rear=newrear;
						flag=2;
						count=1;
						break;
					}
					else{
							n--;
							front=front->next;
							rear=newrear;
							flag=2;
							count=1;
							break;
						}
				}
				else{
				if(count%3!=0){
					newrear->next=front;
					newrear=newrear->next;
					front=front->next;
					count++;
				}
				else{
					count++;
					n--;
					front=front->next;
				}
			}
			}				
		}
	}
	while(front!=rear){
		printf("%d ",front->data);
		front=front->next;
	}
	printf("%d",front->data);
	return 0;
}







