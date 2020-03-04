#include<stdio.h>

long long a[41];

int main()
{
    int n;
    a[1] = 1;
    a[2] = 1;
    int i;
    for(i = 3; i < 41; i++)
        a[i] = a[i-1] + a[i-2];

    while(~scanf("%d",&n))
    {
        for(i = 1; i <= n; i++)
           printf("%ld ",a[i]);
        printf("\n");
    }
    return 0;
}
