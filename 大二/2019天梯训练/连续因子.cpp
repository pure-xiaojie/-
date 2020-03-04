#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int n=sqrt(N);
    int i,j;
    long long int sum;
    for(int len=11; len>=1; len--) //len控制连续因子的个数，由于N范围的限制最多只能到12的阶乘
    {
        for( i=2; i<=n; i++) //连续因子不包括1，从2开始乘，最大乘到N开方就肯定够了
        {
            sum=1;
            for(  j=i; j<=len-1+i; j++) //从当前的i开始，乘以的个数为len的长度
            {
                sum*=j;
                if(sum>N)//到这就没有必要往下算了
                    break;
            }
            if(N%sum==0)//当前的sum值是N的一个因子
            {
                printf("%d\n%d",len,i);
                for(int k=i+1; k<j; k++)
                    printf("*%d",k);
                printf("\n");
                return 0;
            }
        }
    }
    printf("1\n%d\n",N);//质数的情况
    return 0;
}
