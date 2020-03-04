/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{   long s=0;
    int m,n,t,i,j;
 scanf("%d%d",&n,&m);
for(i=n;i<=m;i++)
   { t=i/2;
        for(j=2;j<=t;j++)
      if(i%j==0)  break;
      if(j>=t+1)  s=s+i*i;
      }
   printf("%ld\n",s);
}
