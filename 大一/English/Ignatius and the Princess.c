#include"stdio.h"
int main()
{
    int N,i,j,a[125][125]= {0};
    while(~scanf("%d",&N))
    {
        for(i=0; i<=N; i++)
            a[i][1]=a[1][i]=1;
        for(i=2; i<=N; i++)
            for(j=1; j<=N; j++)
            {
                if(i>j)
                    a[i][j]=a[i-j][j]+a[i][j-1];
                else if(i==j)
                       a[i][j]=1+a[i][j-1];
                     else
                       a[i][j]=a[i][i];
            }
        printf("%d\n",a[N][N]);
    }
    return 0;
}
