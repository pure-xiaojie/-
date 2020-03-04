#include <stdio.h>
main()
{
    int a[100];
    int i,j,k,n;
    scanf("%d",&k);
    while(k--)
    {
    scanf("%d",&n);
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
    int b[20];
    for(i=0;i<n;i++)
    {
        b[i]=1;
        for(j=0;j<i;j++)
         if(a[i]>a[j]&&b[j]+1>b[i])
            b[i]=b[j]+1;

    }
    int t=0;

    for(i=0;i<n;i++)
      if(b[i]>t)
        t=b[i];
    printf("%d\n", t);
    }

}
