#include"stdio.h"
#include"math.h"
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b,i,d,n;
        scanf("%lld%lld",&a,&b);
        int c[b + 1];
        for(i=2; i<=b; i++)
            c[i]=1;
        for(d=2; d*d<=b; d++)
            if(c[d])
                for(n=d*d; n<=b; n+=d)
                    c[n]=0;

        if(a==1)
            a++;
        for(i=a; i<=b; i++)
            if(c[i])
                printf("%lld ",i);
        putchar('\n');
    }
    return 0;
}
