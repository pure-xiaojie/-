#include"stdio.h"
main()
{
   int m,n,i,j,a[100],b[100];
   scanf("%d",&m);
   for(i=0;i<m;i++)
    scanf("%d",&a[i]);
    scanf("%d",&n);
   for(i=0;i<n;i++)
    scanf("%d",&b[i]);
   for(i=m-1,j=n-1;i>=0&&j>=0;)
    if(a[i]>b[j])
     {printf("%d ",a[i]);i--;}

   else
     {printf("%d ",b[j]);j--;}

     if(i==-1)
        for(;j>=0;j--)
        printf("%d ",b[j]);
     if(j==-1)
        for(;i>=0;i--)
        printf("%d ",a[i]);
}
