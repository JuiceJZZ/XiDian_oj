#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAXSIZE 1000
typedef struct Stack{
	char sta[MAXSIZE];
	int top;	
}Stack;
void PushElement(char data,Stack* st){
	st->sta[++st->top]=data;	
}
void dfs(char* s,int i);
void Translate(char* res);
int main(){
	char ss[MAXSIZE];
	char* s=ss;
	scanf("%s",s);
	char res[MAXSIZE]="";
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='('){
			dfs(s,i);
			i--;//极为重要，由于递归结束后s字符串改变，所以i++后会跳过一个元素，出现错误！！
		}
		else{
			int now=strlen(res);
			res[now]=s[i];
		}
	}
	Translate(res);//最后再对A和B进行处理
	return 0;
}
void dfs(char* s,int i){
	Stack* paren=(Stack*)malloc(sizeof(Stack));
	paren->top=-1;
	char se=s[i+1];
	int ded;
	for(int j=i+2;j<strlen(s);j++){
		if(s[j]=='('){
			dfs(s,j);
			j--;//极为重要，原因同理
		}
		else if(s[j]==')'){
			ded=j;
			break;
		}
		else{
			PushElement(s[j],paren);
		}
	}
	//p3就是括号里的元素
	char p3[MAXSIZE]={0};
	int k=0;
	while(paren->top!=-1){
		p3[k++]=se;
		p3[k++]=paren->sta[paren->top--];
	}
	p3[k++]=se;
	k=0;
	//p1是左括号之前的部分，例如s=sdh(dh(hsbdj)),则p1=sdh(dh
	char p1[MAXSIZE]={0};
	strncat(p1,s,i);
	//p2是右括号后面的部分，如p2=)
	char p2[MAXSIZE]="";
	for(int j=ded+1;j<strlen(s);j++){
		p2[k]=s[j];
		k++;		
	}
	strcat(p1,p3);
	strcat(p1,p2);
	strcpy(s,p1);
	//更新s字符串
}
void Translate(char* res){
	int i=0;
	while(*(res+i)){
		if(*(res+i)!='A'&&*(res+i)!='B'){
			printf("%c",*(res+i));
		}
		else{
			if(*(res+i)=='A'){
				printf("sae");
			}
			if(*(res+i)=='B')
			{
				printf("tsaedsae");
			}
		}
		i++;
	}
}

