#include<stdio.h>
#include<stdlib.h>

#define type double
#define maxn 2000
int main()
{
    char c;
    type sum,n,a[maxn];
    int i,j;
    while(scanf("%lf",&n))
    {
        a[0]=n;
        if(n==0)
        {
            c=getchar();
            if(c=='\n')
                break;
        }
        i=1;
        while(1)
        {
            c=getchar();
            if(c=='+')
            {
                scanf("%lf",&a[i]);
                a[i]=a[i];
                i++;
            }
            if(c=='-')
            {
                scanf("%lf",&a[i]);
                a[i]=-a[i];
                i++;
            }
            if(c=='/')
            {
                scanf("%lf",&a[i]);
                a[i]=a[i-1]/a[i];
                a[i-1]=0;
                i++;
            }
            if(c=='*')
            {
                scanf("%lf",&a[i]);
                a[i]=a[i-1]*a[i];
                a[i-1]=0;
                i++;
            }
            if(c=='\n')
                break;
        }
        sum=0;
        for(j=0; j<i; j++)
            sum=sum+a[j];
        printf("%.2lf\n",sum);
    }
    return 0;
}
