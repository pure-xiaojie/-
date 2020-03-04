#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;
#define max1 1000001
long long a[max1],c[max1]= {0};

bool compare(long long a,long long b)
{
    return a>b;
}

int main()
{
    long long n,m,i,k;

    while(~scanf("%lld %lld",&n,&m))
    {
        memset(c,0,sizeof(c));
        for(i=0; i<n; i++)
            scanf("%lld",&a[i]);
        sort(a,a+n,compare);

        for(i = 0,k = 0; i < n; i++)
            if(!c[a[i]+500000])
            {
                if(k<m-1)
                    printf("%lld ",a[i]);
                else
                {
                    printf("%lld",a[i]);
                    break;
                }
                c[a[i]+500000]=1;
                k++;

            }
       printf("\n");
    }
    return 0;
}

