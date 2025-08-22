/*写一个算法统计在输入字符串中各个不同字符出现的频度并
将结果存入文件（字符串中的合法字符为A-Z这26个字母和0-9这10个数字）*/
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
	FILE*pf=fopen("D:/输出.txt","w");
	if(pf!=NULL){
		for(int j=0;j<36;j++){
			fprintf(pf,"%d ",frequence[j]);
		}
	}
	fclose(pf);
}
/*设计一个递归算法，实现字符串的逆序存储，不另设串存储空间*/
/*即第一个输入的字符最后存储，最后输入的字符先存储*/
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
