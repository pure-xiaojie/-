#include"stdio.h"
main()
{
    long long a[20000],i,j,n,min=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&a[i]);

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
    for(i=0;n-1>i;i++)
    {
        int sum=a[i]+a[i+1];
        min=min+sum;
        for(j=i+2;n>j;j++)
            if(sum>a[j])
            {
                a[j-1]=a[j];
                if(j==n-1)
                 a[j]=sum;

            }
            else
            {
                a[j-1]=sum;
                break;
            }

    }
    printf("%lld",min);

}
