#include"stdio.h"
main()
{
    long long n,m;
    while(~scanf("%lld%lld",&n,&m))
    {
        long long x=(m-2*n)/4;
        for(;x<=n;x++)
         if(x*4+(n-x)*2==m)
          {printf("%lld %lld\n",n-x,x);break;}
        if(x>n)
         printf("No answer\n");
    }
}
