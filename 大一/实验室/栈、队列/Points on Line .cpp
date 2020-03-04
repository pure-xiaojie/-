#include<algorithm>
#include<iostream>
#include<stdio.h>

using namespace std;
#define N 100100
int num[N];

int main()
{
    long long m,n,t,i,sum;
    while(~scanf("%lld %lld",&n,&m))
    {
        sum=0;
        for(i=0; i<n; i++)
            scanf("%d",&num[i]);
        for(i=0; i<n-2; i++)
        {
            t=upper_bound(num,num+n,num[i]+m)-num;
            sum+=(t-i-1)*(t-i-2)/2;
        }
        cout << sum <<endl;

    }
return 0;
}
