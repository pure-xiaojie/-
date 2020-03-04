#include"stdio.h"
main()
{
    int i,j,k,sum,n,a[6];
    while( ~scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]))
    {
        int w[6]={1,2,3,5,10,20};
        sum=0;
        for(i=0;i<6;i++)
        {

            sum+=w[i]*a[i];
        }
        if(!sum)
            break;
        int dp[1001]={0};
        dp[0]=1;
        for(i=0;i<6;i++)
          for(k=a[i];k>0;k--)
            for(j=sum;j>=w[i];j--)
             if(dp[j-w[i]])
              dp[j]=1;

        n=0;
        for(i=1;i<=sum;i++)
        {
            if(dp[i])
            n++;
        }

        printf("TOTAL=%d\n",n);
    }

}
