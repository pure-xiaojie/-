#include<iostream>
using namespace std;
int main(){
	int s[10];//����һ�������¼0~9���ֵĴ���
	for(int i=123;i<333;i++){
		for(int m=0;m<10;m++)
			s[m]=0;
		s[i/100]=1;
		s[i/10%10]=1;
		s[i%10]=1;
		int j=i*2;
		s[j/100]=1;
		s[j/10%10]=1;
		s[j%10]=1;
		int k=i*3;
		s[k/100]=1;
		s[k/10%10]=1;
		s[k%10]=1;
		int sum=0;
		for(int m=1;m<10;m++)
			sum+=s[m];
		//��1~9ÿ�����ֳ��ִ������������������9��ÿ�����ֶ�������һ��
		if(sum==9) cout<<i<<" "<<j<<" "<<k<<endl;
	}
	return 0;
}
