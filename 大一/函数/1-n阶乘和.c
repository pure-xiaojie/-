/* Note:Your choice is C IDE */
#include<stdio.h>

long long forone(int x)
{   

    if(x==1)
    return 1;
    else
    return x*forone(x-1);
}

long long forall(long long n)
{   

    return n;
}


int main()
{
    long long int sum=0,a[50];

    int n,i;

    scanf("%d",&n);

    for(i=n;i>=1;i--)
      a[i]=forone(i);
     for(i=n;i>=1;i--)
     sum+=forall(a[i]);
    printf("%lld",sum);
return 0;
}
