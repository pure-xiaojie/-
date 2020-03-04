#include<stdio.h>

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int main()
{
    int sum;
    scanf("%d",&sum);
    int i,j,a[sum][sum],b[1001];

    for(i=0;i<sum;i++)
        for(j=0;j<i+1;j++)
            scanf("%d",&a[i][j]);

    for(i=0;i<sum;i++)
        b[i]=a[sum-1][i];

    for(i=sum-1-1;i>=0;i--)
        for(j=0;j<=i;j++)
            b[j]=max(b[j],b[j+1])+a[i][j];

    printf("%d",b[0]);
    return 0;
}
