/*��ͼ��������������֮������·����
�����ʽ
	�������ݵ�һ����һ������������ʾͼ�еĶ������n��
	���㽫�ֱ�0��1������n-1���б�ţ���֮���n��ÿ�ж�����n��������
	��i�е�j������ʾ����i-1�Ͷ���j-1֮��ı߳�����10000����ʾ��������֮���ޱߡ�
	����ÿ��2�����֣���ʾһ�Դ������·���Ķ��㣬��-1 -1��ʾ���������
	-1 -1����⡣
�����ʽ
ÿ�Դ������·���Ķ�������������ݣ���һ������������������·�����ȣ�
�ڶ���������·����Ҫ��˳��������������У�������ÿո��������
���������û��·��ʱ��ֻ��һ��������ַ�����NO����
��������
7
0 12 10000 10000 10000 10000 10000
12 0 10000 10000 3 10000 10000
10000 10000 0 10000 10000 21 11
10000 10000 10000 0 10000 10000 10000
10000 3 10000 10000 0 10000 8
10000 10000 21 10000 10000 0 10000
10000 10000 11 10000 8 10000 0
0 2
0 3
5 0
2 1
1 5
-1 -1
�������
34
0 1 4 6 2
NO
55
5 2 6 4 1 0
22
2 6 4 1
43
1 4 6 2 5*/
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_SIZE 100
const int MAX_VALUE=10000;
typedef struct Stack{
	int stack[MAX_SIZE];
	int top;
}Stack;
Stack* InitSatck(){
	Stack* st=(Stack*)malloc(sizeof(Stack));
	st->top=-1;
	return st;
}
bool IsEmpty(Stack* st){
	return st->top==-1;
}
void Push(Stack* st,int data){
	st->stack[++st->top]=data;
}
int Pop(Stack* st){
	return st->stack[st->top--];
}
void PrintRoad(Stack* st){
	while(!IsEmpty(st)){
		printf("%d ",Pop(st));
	}
	printf("\n");
}
int main(){
	int n;
	Stack* st=InitSatck();
	scanf("%d",&n);
	int arcs[MAX_SIZE][MAX_SIZE]={0};
	int D[MAX_SIZE][MAX_SIZE]={0};
	int Path[MAX_SIZE][MAX_SIZE]={0};
	//�����ڽӾ���ͳ�ʼ��D�����Path����
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arcs[i][j]);
			D[i][j]=arcs[i][j];
			if(D[i][j]<MAX_VALUE&&i!=j){
				Path[i][j]=i;
			}
			else
			Path[i][j]=-1;
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(D[i][k]+D[k][j]<D[i][j]){
					D[i][j]=D[i][k]+D[k][j];
					Path[i][j]=Path[k][j];
				}
			}
		}
	}
	while(true){
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		if(v1==-1&&v2==-1)
		break;
		if(D[v1][v2]==MAX_VALUE){
			printf("NO\n");
		}
		else{
			printf("%d\n",D[v1][v2]);
			//��·��ѹջ
			int v3=Path[v1][v2];
			Push(st,v2);
			while(v3!=v1){
				Push(st,v3);
				v3=Path[v1][v3];
			}
			Push(st,v1);
			PrintRoad(st);
		}
	}
	return 0;
}
