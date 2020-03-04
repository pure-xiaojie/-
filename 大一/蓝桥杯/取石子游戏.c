#include"stdio.h"
#include"math.h"
int main()
{
    long long a,b,k;
    scanf("%lld",&k);
    while(k--)
    {
    scanf("%lld%lld",&a,&b);
    if(a<b)
    {
        long long temp=a;
        a=b;
        b=temp;
    }
    if (floor((a-b)*((sqrt(5.0)+1.0))/2.0)==b)
      printf("0\n");
    else
      printf("1\n");
    }

}

