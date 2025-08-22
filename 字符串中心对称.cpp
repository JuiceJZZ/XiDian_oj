/*对于有n个字符的字符串，设计算法判断字符串是否中心对称。例如，xyzzyx和xyzyx都是中心对称的字符串。
输入说明：
每组数据有2行：第一行为整数n，表示字符的个数，n小于100；第二行为n个字符组成的字符串。
输出说明：
判断这个字符串是否是中心对称的，是输出“YES”，不是输出“NO”。
输入样例：
12
ThanksThanks
输出样例：
NO*/
#include<stdio.h>
#define MAXSIZE 1000
int main(){
	int n;
	scanf("%d",&n);
	char str[MAXSIZE]={0};
	scanf("%s",str);
	int j=n-1;
	int i=0;
	while(j>=i){
		if(str[j]!=str[i]){
			printf("NO");
			return -1;
		}
		j--;
		i++;
	}
	printf("YES");
	return 0;
}
