#include <stdio.h>
int main()
{
    long long a,b;
    while(~scanf("%lld%lld",&a,&b))
    {
    int ans=1,temp=a%10;
    while(b)
    {
        if(b%2)
        ans=ans*temp%10;

        temp=temp*temp%10;
        b/=2;
    }

    printf("%d\n",ans);
    }
 return 0;
}
