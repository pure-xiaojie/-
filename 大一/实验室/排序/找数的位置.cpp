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
        j=(unsigned long)i-1;    //��С�ڸ���ʵ��i����С����/floor(�෴)
        n=n-j*(j+1)/2;

        if(n%9)
            printf("%d\n",n%9);
        else
            printf("9\n");
    }
    return 0;
}
