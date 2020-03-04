#include<stdio.h>
int main()
{
    int n,m,i,t,sum,j,k;
    scanf("%d%d",&n,&m);

    int a[2001],b[2001];
    sum=0;
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<m; i++)
    {
        scanf("%d",&b[i]);
    }
    for(j=0; j<n-1; j++)
        for(i=0; i<n-j-1; i++)
        {
            if(a[i]>a[i+1])
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }

    for(j=0; j<m-1; j++)
        for(i=0; i<m-j-1; i++)
        {
            if(b[i]>b[i+1])
            {
                t=b[i];
                b[i]=b[i+1];
                b[i+1]=t;
            }
        }


    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
        {
            if(a[i]>b[j]&&b[j]!=0)
            {
                sum++;
                b[j]=0;
                i++;
            }
        }
    printf("%d",m-sum);

    return 0;
}
