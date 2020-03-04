#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<cstring>

#define type long long
#define N 1001

using namespace std;

bool cmp(long long a,long long b)
{
	return a<b;
}

int main()
{
	type i,j,n,flag;
	char c[N];
	type number[N],tempsum;
	while(~(scanf("%s",c)))
	{
		i=strlen(c),j=0;
		for(n=0;j<i;n++)
		{
			flag=0;
			tempsum=0;
			for(;c[j]!='5'&&j<i;j++)
			{
				tempsum=tempsum*10+(c[j]-'0');
				flag=1;
			}
			number[n]=tempsum;
			j++;
			if(!flag)
				n--;
		}
		sort(number,number+n,cmp);
		for(i=0;i<n-1;i++)
			printf("%lld ",number[i]);
        printf("%lld",number[i]);
		printf("\n");
	}
	return 0;
}
