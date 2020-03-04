#include"stdio.h"
long judge(long n)
{
    long sum=0, i;
    for(i=1;i<=n/2;i++)
        if(n%i==0)
        sum+=i;

    return sum;
}
main()
{
    long m,a,b;
    scanf("%ld",&m);
    while(m--)
    {
        scanf("%ld%ld",&a,&b);
        if(judge(a)==b&&judge(b)==a)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
