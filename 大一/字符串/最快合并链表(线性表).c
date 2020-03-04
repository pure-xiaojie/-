#include"stdio.h"
void main()
 {
     int i,m,n,a[65537],b[65537];
     char c,d;
         scanf("%c%c%d",&d,&c,&m);

         for(i=0;i<m;i++)
         scanf("%d",&b[i]);

          scanf("\n%c%c%d",&c,&d,&n);

         for(i=0;i<n;i++)
         scanf("%d",&a[i]);

         for(i=0;i<m;i++)
          printf("%d ",b[i]);
         for(i=0;i<n;i++)
          printf("%d ",a[i]);
 }

