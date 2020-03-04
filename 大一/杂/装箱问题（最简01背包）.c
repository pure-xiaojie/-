#include<stdio.h>

int main()
{
    int v, n,d[31],f[20001]={0};
    scanf("%d%d",&v,&n);
    int i,j;
    for (i = 0; i < n; i++)
        scanf("%d",&d[i]);

    for(i=0;i<n;i++)
     for(j=v;j>=d[i];j--)
        if(f[j]<f[j-d[i]]+d[i])
            f[j]=f[j-d[i]]+d[i];
    printf("%d",v-f[v]);
    return 0;

}
