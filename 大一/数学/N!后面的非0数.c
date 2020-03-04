#include<stdio.h>
#include<string.h>
#define N 30000

int main()
{
    int i,j,n,a[N]={0};
     while(~scanf("%d",&n))
      {

        a[0]=1;
        for(i=2; i<=n; i++)
        {
            int c=0;
            for(j=0; j<N; j++)
            {
                int s=a[j]*i+c;
                a[j]=s%10;
                c=s/10;
            }
        }
        for(j=N-1; j>=0; j--)
            if(a[j])
                break;
        for(i= 0;i<=j;i++)
          if(a[i]!=0)
           {
              printf("%d\n",a[i]);
              break;

           }

      }
    return 0;
}

