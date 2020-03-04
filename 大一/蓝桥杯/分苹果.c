#include"stdio.h"
int fun(int m,int n)
{
    if(m==1 || m==0 || n==1)
        return 1;
    else if(m<n)
        return fun(m,m);
    else
        return fun(m-n,n)+fun(m,n-1);
}
main()
{
    int a,b,n;
    scanf("%d",&n);
    while(n--)
    {
    scanf("%d%d",&a,&b);
    printf("%d\n",fun(a,b));
    }
}
