/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{  int n,i,j,t,s=0,a[100];
   scanf("%d",&n);
   for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    if(a[i]>=a[j]) 
     {t=a[i];a[i]=a[j];a[j]=t;++s;}
     printf("%d",s);
 return 0;
}
     
