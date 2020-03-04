#include<stdio.h>
void main()
{
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int i;
        int a[100],b[100],sort[200]={0};
        for(i=0;i<m;i++)
            {
                scanf("%d",&a[i]);
                sort[a[i]]++;
            }
        for(i=0;i<n;i++)
            {
                scanf("%d",&b[i]);
                sort[b[i]]++;
            }
        for(i=0;i<m;i++)
            if(sort[a[i]]==1)
              printf("%d ",a[i]);
         putchar('\n');
        for(i=0;i<n;i++)
            if(sort[b[i]]==1)
               printf("%d ",b[i]);
         putchar('\n');

    }

}

