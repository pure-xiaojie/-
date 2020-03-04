#include<stdio.h>

int main()
{
    int i,j,n,max=0,tria[100][100];
    scanf("%d",&n);

    for(i=1; i<=n; i++)
        for(j=1; j<=i; j++)
        {
            scanf("%d",&tria[i][j]);
            if(tria[i-1][j]>tria[i-1][j-1])
                tria[i][j]+=tria[i-1][j];
            else
                tria[i][j]+=tria[i-1][j-1];
            if(i==n&&max<tria[i][j])
                max=tria[i][j];
        }
    printf("%d",max);
    return 0;
}
