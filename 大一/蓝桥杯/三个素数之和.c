#include"stdio.h"
#include"math.h"
int a[1000];
int Judge_Prime(int m)
{
    int i,j,k;
    a[0]=a[1]=0;
    for(i=2;i<1000;i++)
    {
        for(j=2;j<=sqrt(i);j++)
            if(i%j==0)
            {
                a[i]=0;
                break;
            }
        if(j>sqrt(i))
            a[i]=1;
    }
 return 0;
}
main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        Judge_Prime(n);
        int i,j,k,m=0,f=0;
        for(i=3;i<=n;i++)
            for(j=i;j<=n;j++)
                for(k=j;k<=n;k++)
                    if(a[i]==1&&a[j]==1&&a[k]==1&&i+j+k==n)
                    {
                        m++;
                        f=1;
                    }

        if(f)
            printf("%d\n",m);
        else
            printf("Error\n");
    }
}
