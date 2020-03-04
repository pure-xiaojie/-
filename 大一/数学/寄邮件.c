#include<stdio.h>
int main()
{
    int t,i;
    long long a[50];
    a[1] = 0;
    a[2] = 1;
    a[3] = 2;
    for(i = 4; i < 22; i++)
        a[i] = (i - 1) * (a[i-1]+a[i-2]);

    while(~scanf("%d",&t))
    {
        while(t--)
        {
            int n;
            scanf("%d",&n);
            printf("%lld\n",a[n]);

        }
    }

    return 0;
}

