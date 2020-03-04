#include"stdio.h"
int a[1000],b[1000],n;
void find(int m,int start,int k)
{
  int i,j;
  for(i=start;i<=m/2;i++)
  {
    a[k]=m-i;
    b[k]=i;
    find(a[k],i,k+1);
    printf("%d=",n);
    for(j=1;j<=k;j++)
     printf("%d+",b[k]);
    printf("%d\n",a[k]);

  }

}

void main()
{
  scanf("%d",&n);
  find(n,1,1);
  printf("%d=%d",n,n);
}
