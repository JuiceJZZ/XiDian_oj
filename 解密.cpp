/*要将"China"译成密码，译码规律是：用原来字母后面的第4个字母代替原来的字母．
例如，字母"A"后面第4个字母是"E"．"E"代替"A"。因此，"China"应译为"Glmre"。
请编一程序，用赋初值的方法使cl、c2、c3、c4、c5五个变量的值分别为，’C’、’h’、’i’、’n’、’a’，经过运算，使c1、c2、c3、c4、c5分别变为’G’、’l’、’m’、’r’、’e’，并输出。
输入格式
　　输入字符串"China"
输出格式
　　加密后的China*/
#include<stdio.h>
#include<string.h>
int main(){
	char s1[1000];
	char s2[1000];
	scanf("%s",s1);
	int n=strlen(s1);
	int i;
	for(i=0;i<n;i++){
		if(s1[i]>='W'&&s1[i]<='Z'){
			s2[i]=s1[i]-22;
			printf("%c",s2[i]);
		}
		else if(s1[i]>='w'&&s1[i]<='z'){
			s2[i]=s1[i]-22;
			printf("%c",s2[i]);			
		}
		else{
			s2[i]=s1[i]+4;
			printf("%c",s2[i]);			
		}

	}
	return 0;
}
