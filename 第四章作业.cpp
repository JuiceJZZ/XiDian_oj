/*дһ���㷨ͳ���������ַ����и�����ͬ�ַ����ֵ�Ƶ�Ȳ�
����������ļ����ַ����еĺϷ��ַ�ΪA-Z��26����ĸ��0-9��10�����֣�*/
#include<stdio.h>
#include<string.h>
int ii=0;
void Count(char* str){
	int frequence[36]={0};
	int i=0;
	while(str[i]){
		if('0'<=str[i]&&str[i]<='9'){
			frequence[str[i]-'0']++;
		}
		if('A'<=str[i]&&str[i]<='Z'){
			frequence[str[i]-'A'+10]++;
		}	
		i++;
	}
	FILE*pf=fopen("D:/���.txt","w");
	if(pf!=NULL){
		for(int j=0;j<36;j++){
			fprintf(pf,"%d ",frequence[j]);
		}
	}
	fclose(pf);
}
/*���һ���ݹ��㷨��ʵ���ַ���������洢�������贮�洢�ռ�*/
/*����һ��������ַ����洢�����������ַ��ȴ洢*/
void InvertStore(char* res){
	char in;
	scanf("%c",&in);
	if(in!='.'){
		InvertStore(res);
		res[ii++]=in;
	}
	res[ii]='\0';
}
int main(){
	char str[20];
	InvertStore(str);
	str[ii]='\0';
	printf("%s",str);
	return 0;
}
