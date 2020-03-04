#include<stdio.h>
int main()
{
    int a[100],b[50],i,m,n,t,k=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    scanf("%d",&m);
    for(i=0; i<n; i++)
        if(a[i]<m)
        b[k++]=a[i];

    for(i=0; i<k; i++)
        for(n=i+1; n<k; n++)
            if(b[i]<b[n])
            {
                t=b[i];
                b[i]=b[n];
                b[n]=t;
            }

    printf("%d\n",k-1);
    for(i=0; i<k; i++)
        printf("%d ",b[i]);
    return 0;
}
