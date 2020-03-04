#include"stdio.h"
main()
{
  int n,a[100]={0};
  a[0]=a[1]=1;
  scanf("%d",&n);
  int i,j,k,wei=1;
  for(i=1;i<=n;i++)
  {
      for(j=1;j<=wei;j++)
        a[j]*=i;

      for(j=1;j<=wei;j++)
      if(a[j]>=10)
      {
          for(k=1;k<=wei;k++)
          {
              if(a[wei]>=10)
                wei++;
              a[k+1]+=a[k]/10;
              a[k]=a[k]%10;
          }
      }

  }
 for(i=wei;i>0;i--)
    printf("%d",a[i]);

}
