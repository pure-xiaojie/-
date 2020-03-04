/* Note:Your choice is C IDE */
#include<stdio.h>
int main()
{
    long long a,b,c,n,t,s;
    scanf("%lld",&n);
    while(n--)
    {
    scanf("%lld%lld",&a,&b);
    c=a*b;
    if(a<b)
    {
     t=a; a=b; b=t;
    }
    int k=a%b;
    while(k)
    {
        a=b;
        b=k;
        k=a%b;
    }
    printf("%lld",c/b);
    if(n>0)
    putchar('\n');
    }

   return 0;
}
