/*���һ���ַ���������ĳ������Ϊk���ַ����ظ���εõ�������˵�ô���kΪ���ڡ����磬abcabcabcabc��3Ϊ���ڣ�ע�⣬��Ҳ��6��12Ϊ���ڣ�������һ�����Ȳ�����80�Ĵ������������С���ڡ�
����˵����
ÿ������Ϊһ���ַ�����
���˵����
���ÿ���ַ�������С���ڡ�
����������
GGeeGGGeeGGGeeG
���������
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
			//Ѱ��s2λ��
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
			//�����ж�
			while(t1!=s2){
				if(str[t1]==str[t2]){
					t1++;
					t2++;
				}else{
					//����Ѱ��s2λ��
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
	//prefix[i] ��ʾ�� s[0] �� s[i] ���Ӵ������ͬǰ��׺�ĳ���
	//prefix[j-1]��ʾ�ص���һ���ǰ��׺�ĳ��ȣ�����s[0]-s[j-1]�����ǰ��׺	
}
bool hasPeriodicity(char *str){
	int n=strlen(str);
	int prefix[MAXSIZE];
	CreatPrefix(str,prefix);
	int t=prefix[n-1];
    // �ж��Ƿ����������
    if (t > 0 && n % (n - t) == 0) {
        return true; // ��������
    }
    return false; // û��������	
}
