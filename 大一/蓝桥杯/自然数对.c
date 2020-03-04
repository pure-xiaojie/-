#include"stdio.h"
#include"math.h"
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);

        if((a+b)==(int)sqrt(a+b)*(int)sqrt(a+b)&&(a-b)==(int)sqrt(a-b)*(int)sqrt(a-b))
            printf("YES\n");
        else
            printf("NO\n");

    }
}
