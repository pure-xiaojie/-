/* Note:Your choice is C IDE */
#include "stdio.h"
int main()
{
    long long a[20];
    int m,n,i,s;
    char t,k;
    for(i=0; i<10; i++)
        scanf("%lld", &a[i]);
    getchar();
    scanf("%c%c%d",&t,&k,&m);
    getchar();
    scanf("%c%c%d",&t,&k,&n);

    for(n=m+n-1; m<n; m++,n--)
    {
        s=a[m];
        a[m]=a[n];
        a[n]=s;
    }

    for(i=0; i<10; i++)
        printf("%lld ", a[i]);
    return 0;
}
