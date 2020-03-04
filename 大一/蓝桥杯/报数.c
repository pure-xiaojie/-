#include"stdio.h"
main()
{
   int p;
   scanf("%d",&p);
   while(p--)
   {
       long long n,m,k=0,i;
       scanf("%lld%lld",&n,&m);
       for(i=2;i<=n;i++)
        k=(k+m)%i;

       printf("%d\n",k+1);


   }

}
