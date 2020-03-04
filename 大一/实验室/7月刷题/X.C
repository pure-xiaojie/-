#include "stdio.h"
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[100][100];
        int i,j,n;
        scanf("%d",&n);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(i==j||i+j==n-1)
                    a[i][j]=1;
                else
                    a[i][j]=0;
        for(i=0; i<n-1; i++)
            for(j=n-1; j>=n/2;j--)
            {
                if (a[i][j] == 0)
                    a[i][j]=2;
                else
                    break;
            }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                if(a[i][j] == 1)
                    putchar('X');
                else if(a[i][j] == 0)
                    putchar(' ');
            printf("\n" );
        }
        if(t)
            printf("\n" );
    }
    return 0;
}
