#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;

#define type long long
#define T 1000000
type a[T],b[T],n,m;

bool compare(int a,int b)
{
    return a<b;
}

int main()
{
    while(~scanf("%lld%lld",&n,&m))
    {
        type i;
        for(i=0; i<n; i++)
            scanf("%lld",&a[i]);
        for(i=0; i<m; i++)
            scanf("%lld",&b[i]);
        sort(a,a+n,compare);
        type t=0,j;
        for(i=0; i<m; i++,t=1)
        {
            type left=0,right=n,mid,temp=b[i],j=0;
            while(left<right)
            {
                mid=(left+right)/2;

                if(temp>=a[mid])
                {
                    j+=mid-left+1;
                    left=mid+1;

                }
                else
                {
                    right=mid;
                }
            }

            if(t)
                putchar(' ');
            printf("%d",j);

        }
        putchar('\n');
    }


    return 0;
}


