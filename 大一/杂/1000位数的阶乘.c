#include<stdio.h>
#include<string.h>
#define N 3000

int main()
{
    int i,j,n,k=1,a[N];
    while(scanf("%d",&n),n)
    {
        memset(a,0,sizeof(a));
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
        printf("Case #%d:\n",k++);
        for(i=j; i>=0; i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
