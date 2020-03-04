#include<stdio.h>
int main()
{
    long long fblq[2000],n;
    int k;
    fblq[0]=0;
    fblq[1]=1;
    for(k=2;k<=2000;k++)
    fblq[k]=(fblq[k-1]+fblq[k-2])%66666;

    while(~scanf("%lld",&n))
    printf("%lld\n",fblq[n%1080]);

return 0;
}
