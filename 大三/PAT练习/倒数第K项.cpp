#include<stdio.h>
#include<string.h>

int a[1000000];

int main()
{

    int k;
    scanf("%d",&k);
    int n,i = 0;
    while(scanf("%d",&n),n >= 0)
    {
        a[i++] = n;
    }
    if(k <= i)
        printf("%d",a[i-k]);
    else
        printf("NULL");
    return 0;
}
