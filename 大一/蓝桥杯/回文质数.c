#include"stdio.h"
#include"math.h"
int main()
{
    long long a,b,p[10000];
    scanf("%lld%lld",&a,&b);
    int i=0,d1,d2,d3,d4;

    for (d1=2; d1<=9; d1+=1)
        p[i++]=d1;

    p[i++]=11;

    for (d1=1; d1<=9; d1+=2)
        for (d2=0; d2<=9; d2++)
            p[i++]=100*d1+10*d2+d1;

    for (d1=1; d1<=9; d1+=2)
        for (d2=0; d2<=9; d2++)
            for (d3=0; d3<=9; d3++)
                p[i++]=10000*d1+1000*d2+100*d3+10*d2+d1;


    for (d1=1; d1<=9; d1+=2)
        for (d2=0; d2<=9; d2++)
            for (d3=0; d3<= 9; d3++)
                for (d4 = 0; d4 <= 9; d4++)
                    p[i++] = 1000000*d1+100000*d2 + 10000*d3 + 1000*d4 + 100*d3+ 10*d2 + d1;


    int n=i-1;
    for(i=0; i<n&&p[i]<=b; i++)
    {
        int j;
        for (j=2; j<=sqrt(p[i]); j++)
            if(p[i]%j==0)
                break;

        if(j>sqrt(p[i])&& p[i]>=a)
            printf("%lld\n",p[i]);

    }

}
