#include <stdio.h>
int main()
{
    long long a[41];
    int i,n;
    a[0]=1;a[1]=2;
    for (i=2;i<40;i++)
    a[i]=a[i-2]+a[i-1];

    while((scanf("%d",&n)==1),n)
    printf("%lld\n",a[n-1]);
}
