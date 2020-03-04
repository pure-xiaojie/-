#include"stdio.h"
#include"math.h"
int main()
{
    long long int a,b,c,n,k=1;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);

            if(abs(a-c)<b&&abs(b-c)<a&&abs(a-b)<c)
            {
                if(a==b&&a==c&&b==c)
                 printf("Case %d: Equilateral\n",k++);
                if(a!=b&&b!=c&&a!=c)
                  printf("Case %d: Scalene\n",k++);
                if((a==b&&a!=c)||(a==c&&a!=b)||(c==b&&c!=a))
                  printf("Case %d: Isosceles\n",k++);


            }

            else
                printf("Case %d: Invalid\n",k++);


    }

    return 0;
}
