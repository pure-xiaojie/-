/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
 long long int i,j,n,t,s=0;
 scanf("%d",&t);
 while(t--)
  {
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   for(j=1;j<=i;j++)
    s+=j;
   printf("%lld\n",s);
   s=0;
  }
return 0;
}