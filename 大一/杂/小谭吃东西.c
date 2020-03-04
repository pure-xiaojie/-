#include<stdio.h>
int main()
{
    long long int a[10],p;
    int n,i,flag=1;;

    while(scanf("%d",&n))
    {

        for(i=0;i<n;i++)
        {
            scanf("%lld",&p);
            a[i]=p;
        }
        for(i=0;i<n;i++)
            if(a[i]==a[i+1])
            {
                 flag=0;
                 break;
            }
        if(flag!=0)
            printf("yes\n");
        else
            printf("no\n");

     }
     return 0;
}
