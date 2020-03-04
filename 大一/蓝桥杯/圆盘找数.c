#include"stdio.h"
main()
{
    int n,i,a[1000],sum[1000]= {0};
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    int j;
    for(i=0; i<n-3; i++)
        for(j=i; j<i+4; j++)
            sum[i]+=a[j];
    int max=0,min=0;
    for(i=1; i<n-3; i++)
        if(sum[i]>sum[max])
            max=i;
    for(i=1; i<n-3; i++)
        if(sum[i]<sum[min])
            min=i;
    printf("%d %d",max+1,min+1);
}
