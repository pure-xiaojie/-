#include<stdio.h>
int main()
{
    int i,j,k,n,m;
    while(~scanf("%d",&n))
    {
        if(n<=0)
         break;
        m=0;
        for(i=0; i<=10*n; i++)
         for(j=0; j<=5*n; j++)
          for(k=0; k<=2*n; k++)
            if((i*10+j*20+k*50)==100*n)
               m++;

        printf("%d\n",m);
    }
    return 0;
}
