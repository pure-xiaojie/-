#include"stdio.h"
main()
{
    int a[4],b[4];
    int i;
    int k1,k2;
    for(i=0;i<4;i++)
      scanf("%d",&a[i]);
    for(i=0;i<4;i++)
      scanf("%d",&b[i]);
      if(a[2]!=a[0])
    k1=(a[3]-a[1])/(a[2]-a[0]);
      if(b[2]!=b[0])
    k2=(b[3]-b[1])/(b[2]-b[0]);


    while(a[0]||a[1]||a[2]||a[3])
    {
        if(k1==-1/k2)
           printf("YES\n");
        else
           printf("NO\n");

         for(i=0;i<4;i++)
      scanf("%d",&a[i]);
     for(i=0;i<4;i++)
      scanf("%d",&b[i]);
    if(a[2]!=a[0])
    k1=(a[3]-a[1])/(a[2]-a[0]);
      if(b[2]!=b[0])
    k2=(b[3]-b[1])/(b[2]-b[0]);
    }

}
