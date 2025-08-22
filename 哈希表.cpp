/*�����ʼ��ϣֵ�����ȸ��ݹؼ��ֺͳ��� p �������ʼ�Ĺ�ϣֵ hash_value = key % p��
����ʼλ�ã������ʼλ�� table[hash_value] Ϊ�գ��� None�����򽫹ؼ��ֲ����λ�á�
����̽�⣺�����ʼλ���ѱ�ռ�ã���ӳ�ʼλ�ÿ�ʼ�����μ�����λ�ã�ֱ���ҵ�һ������λ��Ϊֹ��
ѭ���������ڹ�ϣ���ǻ��νṹ��������Ҫʹ��ȡģ���� (hash_value + i) % m ��ȷ�������ڱ���Χ��ѭ����
����ؼ��֣�һ���ҵ�����λ�ã��ͽ��ؼ��ֲ����λ�á�*/
/*�ó���������������̽����ɢ�еĳ�ͻ������������ϣ��
���룺
	�������ݵ�һ��Ϊ�����������ֱ�Ϊ����ϣ���m��m<100���ͳ���p��p<=m��������ÿһ����һ�������ؼ��֣���-1��Ϊ����Ľ�����
�����
������Ĺؼ����ڹ�ϣ�����Ѵ��ڣ�������ùؼ����ڹ�ϣ���е�λ�ã������ȴ�������һ���ؼ��֡�
������Ĺؼ����ڹ�ϣ���в����ڣ����жϵ�ǰ��ϣ���йؼ��ֵĸ����Ƿ����m-1������ȣ�
�������Table full����������������򽫹ؼ��ֲ����ϣ��
������ùؼ��ֲ����ڹ�ϣ���е�λ�ã������ȴ�������һ���ؼ��֡�*/
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
	hash[i]=-1;//����-1������Ľ�����־����˿���������ʼ��hash���飬��Ϊδʹ�õı�־
	int input[MAX_SIZE];
	int i=0;
	int count=0;//���ڼ�¼hash�������ڷ��˶��ٸ�Ԫ��
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
			//�п��ܵ�ǰ��key��λ�����Ѿ����������ռ���ˣ����Ҫ����̽��
			while(hash[key]!=input[i]){
				key=(key+1)%m;
			}
			printf("%d\n",key);
		}
		i++;
	}
	return 0;
}


