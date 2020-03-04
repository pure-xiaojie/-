/* Note:Your choice is C IDE */
#include "stdio.h"
int main()
{
  int a[10],m,n,i,s;
  char t,k;
  for(i=0; i<10; i++)
    scanf("%d", &a[i]);
    scanf("%c%c%d",&t,&k,&m);getchar();
    scanf("%c%c%d",&t,&k,&n);
  for(n=m+n-1;m<n;m++,n--)
    {   s=a[m-1];
    	a[m-1]=a[n-1];
    	a[n-1]=s;
    }
  for(i=0; i<10; i++)
    printf("%d ", a[i]);
    printf("\b");
  return 0;
}
