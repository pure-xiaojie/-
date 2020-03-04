#include <stdio.h>

int main()
{
    int  n,m,i,j,sum;
    while(~scanf("%d%d",&n,&m))
    {
        sum=0;
        while(n)
        {
            sum += n/m;
            n /= m;
        }
        printf("%d\n",sum);
    }
    return 0;
}

