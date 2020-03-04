#include<stdio.h>
int main()
{
    int N,i,j,a[100][100];
    while(~scanf("%d",&N))
    {
        a[0][0]=1;
        printf("%d",a[0][0]);
        for(i=0; i<N-1; i++)
        {
            a[i+1][0]=a[i][0]+i+1;
            for(j=0; j<N-i-1; j++)
            {
                a[i][j+1]=a[i][j]+j+i+2;
                printf(" %d",a[i][j+1]);
            }
            printf("\n%d",a[i+1][0]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
