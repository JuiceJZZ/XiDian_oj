/*如果一个字符串可以由某个长度为k的字符串重复多次得到，我们说该串以k为周期。例如，abcabcabcabc以3为周期（注意，它也以6和12为周期）。输入一个长度不超过80的串，输出它的最小周期。
输入说明：
每组数据为一个字符串。
输出说明：
输出每组字符串的最小周期。
输入样例：
GGeeGGGeeGGGeeG
输出样例：
3*/
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define MAXSIZE 100
bool IsSingleCircle(char* str);
void CreatPrefix(char* str,int* prefix);
bool hasPeriodicity(char *str);
int main(){
	char str[MAXSIZE];
	scanf("%s",str);
	if(IsSingleCircle(str)){
		printf("1");
		return -1;
	}else{
		if(hasPeriodicity(str)){
		int s1,s2,t1,t2;
			int i=2;
			s1=0;
			t1=s1+1;
			//寻找s2位置
			while(true){
				if(str[i]==str[s1]){
					s2=i;
					t2=s2+1;
					break;
				}
				else{
					i++;
				}
			}
			//周期判断
			while(t1!=s2){
				if(str[t1]==str[t2]){
					t1++;
					t2++;
				}else{
					//重新寻找s2位置
					i=s2+1;
			while(true){
				if(str[i]==str[s1]){
					s2=i;
					t2=s2+1;
					break;
				}
				else{
					i++;
				}
			}
				t1=s1+1;		
		}
				
	}	
	printf("%d",t1);}	
	else{
		printf("%d",strlen(str));
		return -2;
	}
}
	return 0;
}
bool IsSingleCircle(char* str){
	int n=strlen(str);
	if(n==1){
		return true;
	}
	else{
		char s=str[0];
		int i=1;
		while(*(str+i)){
			if(str[i]!=s)
			return false;
			i++;
		}
	}
	return true;
}
void CreatPrefix(char* str,int* prefix){
	int n=strlen(str);
	prefix[0]=0;
	for(int i=1,j=0;i<n;i++){
		while(j>0&&str[i]!=str[j]){
			j = prefix[j - 1];
		}
		if(str[i]==str[j]){
			j++;
		}
		prefix[i]=j;
	}
	//prefix[i] 表示从 s[0] 到 s[i] 的子串的最长相同前后缀的长度
	//prefix[j-1]表示回到上一个最长前后缀的长度，即是s[0]-s[j-1]的最大前后缀	
}
bool hasPeriodicity(char *str){
	int n=strlen(str);
	int prefix[MAXSIZE];
	CreatPrefix(str,prefix);
	int t=prefix[n-1];
    // 判断是否具有周期性
    if (t > 0 && n % (n - t) == 0) {
        return true; // 有周期性
    }
    return false; // 没有周期性	
}
