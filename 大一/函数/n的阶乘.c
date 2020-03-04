/* Note:Your choice is C IDE */
#include <stdio.h>

long long all(int n)
{
 if(n==0)
  return 1;
 else
  return n*all(n-1);
}

void main()
{
 int n;
 
 scanf("%d",&n);
    
 printf("%lld\n",all(n));

} 