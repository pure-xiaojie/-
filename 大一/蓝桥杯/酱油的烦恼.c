#include"stdio.h"
main()
{
    long long n,m,i,p[1000];
    while(~scanf("%lld %lld",&n,&m))
    {
        for(i=0; i<n; i++)
            scanf("%lld",&p[i]);
        int f=0;
        int a,b,c,d;
        for(a=0; a<n; a++)
            for(b=0; b<n; b++)
                for(c=0; c<n; c++)
                    for(d=0; d<n; d++)
                        if(p[a]+p[b]+p[c]+p[d]==m)
                            f=1;
        if(f)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
