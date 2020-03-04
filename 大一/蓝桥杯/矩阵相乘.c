#include"stdio.h"
#include"string.h"
 main()
{
    int m,n,k,i,j;
    int a[15][15],b[15][15];
    scanf("%d %d %d",&m,&n,&k);

    for(i=0;i<m;i++)//第一个矩阵的行//
     for(j=0;j<n;j++)//第二个矩阵的列//
      scanf("%d",&a[i][j]);

    for(i=0;i<n;i++)//第二个矩阵的行//
     for(j=0;j<k;j++)//第二个矩阵的行列/
      scanf("%d",&b[i][j]);

    int c[m][k];
    for(i=0;i<m;i++)
     for(j=0;j<k;j++)
     {
         c[i][j]=0;
         int t;
         for(t=0;t<n;t++)
         c[i][j]+=a[i][t]*b[t][j];
     }
    for(i=0;i<m;i++)
     {
        for(j=0;j<k;j++)
        {
         printf("%d",c[i][j]);
         if(j<k-1)
          putchar(' ');
        }
        putchar('\n');
     }
}
