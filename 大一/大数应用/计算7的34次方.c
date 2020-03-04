#include"stdio.h"
main()
{
    int i,j,k,c=0,a[34];
    a[0]=1;
    k=0;
    for(i=1;i<=34;i++)
    {
        for(j=0;j<=k;j++)
        {
            a[j]=a[j]*7+c;
            c=a[j]/10;
            a[j]%=10;
        }
        if(c)
        {
            k++;
            a[k]=c;
            c=0;
        }
    }
    for(;k>=0;k--)
        printf("%d",a[k]);
    printf("\n");
return 0;
}
