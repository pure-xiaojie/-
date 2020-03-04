#include<stdio.h>
int main()
{
    long long a;
    scanf("%lld",&a);
    long long m=0,b[100];
    int n,k,t,i=0;
    while(a)
    {
        b[i++]=a%10;
        a/=10;

    }
    n=i-1;
    k=i;
    for(i=n; i>=0; i--)
        if(b[i]%2==0)
        {
            t=b[i];
            b[i]=b[0];
            b[0]=t;
            break;
        }
    if(i==-1)
        printf("%d",-1);
    else
    {
        for(i=n; i>=0; i--)
        {
            k=i;
            while(k--)
                b[i]*=10;
            m+=b[i];

        }
        printf("%lld",m);
    }
    return 0;
}
