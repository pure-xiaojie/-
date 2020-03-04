/* Note:Your choice is C IDE */
#include <stdio.h>
void main()
{
int i=2,n;
scanf("%d",&n);
while(n)
{
  if(n%i==0)
  {
  	printf("%d ",i);
    n/=i;
  }
  else 
    i++;
}
return 0;
}