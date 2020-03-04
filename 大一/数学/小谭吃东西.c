#include"stdio.h"
int main()
{
    long long int a[10],p;
    int n,i,j,flag=1;

    while(~scanf("%d",&n))
    {
        p=0;
        for(i=0;i<n;i++)
        scanf("%lld",&a[i]);
        if(n==1)
        {
           if(a[0]>=2)
             printf("no\n");
           else
             printf("yes\n");
        }

        else
        { flag=a[0];j=0;
           for(i=0;i<n;i++)
            if(a[i]>flag)
              {
                  j=i;
                  flag=a[i];
              }

           for(i=0;i<n;i++)

              {
                  if(j!=i)
                  p+=a[i];
              }

        if(p>=flag)
            printf("yes\n");
        else
            printf("no\n");
        }



     }
     return 0;
}
