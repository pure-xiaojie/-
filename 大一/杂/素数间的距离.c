#include<stdio.h>
#include "math.h"
int fun(int n)
    {

        int i;
        for (i=2;i<=sqrt(n);++i)
        if(n%i==0)
          break;

        if(i>sqrt(n))
            return 1;
        else
            return 0;
    }


void main()
{

      int m;
      scanf("%d",&m);
      while(m--)
      {
       int n,i,k=0,a[10000];
       long long sum=0;
       scanf("%d",&n);
       if(n>4)
       {
        for(i=2;i<=n;i++)
          if(fun(i))
          a[k++]=i;
       int x,y;
       for(x=0;x<k-1;x++)
        for(y=x+1;y<k;y++)
          sum+=fabs(a[x]-a[y]);
        printf("%lld\n",sum);
       }
       else if(n==3||n==4)
             printf("%lld\n",5);
            else
             printf("%lld\n",sum);


      }

}
