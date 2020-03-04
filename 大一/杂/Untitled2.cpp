#include<iostream>
using namespace std;
int main(){
	int s[10];//定义一个数组记录0~9出现的次数
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
		//将1~9每个数字出现次数加起来，如果等于9则每个数字都出现了一次
		if(sum==9) cout<<i<<" "<<j<<" "<<k<<endl;
	}
	return 0;
}
