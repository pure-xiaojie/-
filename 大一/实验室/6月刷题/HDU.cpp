#include<stdio.h>
main()
{
    int n;
    scanf("%d",&n);
    char a[4]="HDU";
    while(n--)
    {
        int i,j,m;
        scanf("%d",&m);
        for(i=0;i<m*3;i++)
           {
               for(j=0;j<m;j++)
                 printf("%s",a);
                 printf("\n");
           }

    }
}
