#include"stdio.h"
#include"string.h"
main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    char a[10000][10],b[10000][10];
    int i,j,k,c[10000]={0};
    for(i=0;i<n;i++)
     scanf("%s",a[i]);
    for(i=0;i<m;i++)
     scanf("%s",b[i]);

     for(i=0;i<n;i++)
      for(j=0;j<10;j++)
      {
         for(k=0;k<m;k++)
         if(!(strcmp(&a[i][j],b[k])))
            c[k]++;
      }
   for(k=0;k<m;k++)
     printf("%d\n",c[k]);

}
