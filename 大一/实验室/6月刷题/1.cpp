#include<stdio.h>
int main()
{
    int t;
    long long n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=1; i<=1000; i++)
            if((i*i*i)>=n)
            {
                 printf("%lld\n",i);
                 break;
            }
            else
                n=n-i*i*i;
    }
    return 0;
}
