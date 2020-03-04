#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int a1=0,a2=0,a3=0,a4=0,a5=0;

    int n,m,t = 1,k = 0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        if(m % 5 == 0 && m % 2 == 0)
            a1 += m;
        if(m % 5 == 1)
        {
            a2 += m*t;
            t *= -1;
        }
        if(m % 5 == 2)
            a3++;
        if(m % 5 == 3)
        {
            a4 += m;
            k++;
        }
        if(m % 5 == 4)
            a5 = max(a5,m);
    }
    if(a1 != 0)
        printf("%d ",a1);
    else
        printf("N ");

    if(a2 != 0)
        printf("%d ",a2);
    else
        printf("N ");

    if(a3 != 0)
        printf("%d ",a3);
    else
        printf("N ");

    if(a4 != 0)
        printf("%.1f ",a4*1.0/k);
    else
        printf("N ");

    if(a5 != 0)
        printf("%d",a5);
    else
        printf("N");
    return 0;
}

