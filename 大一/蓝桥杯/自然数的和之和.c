#include"stdio.h"
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,i;
        long long a=1,b=1,c=1;
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;i++)
            a*=i;
        for(i=1;i<=n;i++)
            b*=i;
        for(i=1;i<=m-n;i++)
            c*=i;

        printf("%lld\n",a/(b*c));
    }
}
