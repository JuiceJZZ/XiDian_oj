/*��֪N���ˣ��Ա��1��2��3��...��N�ֱ��ʾ���ų�һ��, ��һ�ִӱ��Ϊ1���˿�ʼ���α���������2�ı������˳��У��ڶ��ִ�ͷ��ʼ���α���������3�ı������˳��У��������ٴδ�ͷ��ʼ���α���������2�ı������˳��У������ִ�ͷ��ʼ���α���������3�ı������˳��У����˹����ظ���ȥ��ֱ�������е���������������Ϊֹ��Ҫ�������ʱ������ʣ�µ����ڳ�ʼ�����еı�š�
�������� 
һ��������N����ʾ��ʼ������N��5000��
������� 
���������ʣ�µ����ڳ�ʼ�����еı�ţ����֮����һ���ո�
�������� 
20
������� 
1 7 19
��ʾ
����ʹ�ö��У�ÿ�β���ʱ�Զ�����Ԫ�ؽ����жϣ�����Ҫ�����ľ����¼�����У�*/
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
	int flag=2;//��־��2�ı�������3�ı���
	int count=1;//��������
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







