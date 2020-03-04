#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int k;
    double i;
    unsigned long j,n;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%ld",&n);

        i=ceil(sqrt(2*n*1.0+0.25)-0.5);
        j=(unsigned long)i-1;    //求不小于给定实数i的最小整数/floor(相反)
        n=n-j*(j+1)/2;

        if(n%9)
            printf("%d\n",n%9);
        else
            printf("9\n");
    }
    return 0;
}
