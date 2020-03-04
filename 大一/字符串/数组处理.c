#include"stdio.h"
int a[2][5];
void abc()
{
    int i,j;
    for(i=0;i<2;i++)
     {
      for(j=0;j<5;j++)
      scanf("%d",&a[i][j]);

     }
}

int average(int i)
{
    int j,average=0;
     for(j=0;j<5;j++)
       average+=a[i][j];
       return average/5.0;
}

int c()
{
    int average=0,i,j;
    for(i=0;i<2;i++)
      for(j=0;j<5;j++)
        average+=a[i][j];
      return average/10.0;
}

int d()
{
     int i,j,max=a[0][0];
     for(i=0;i<2;i++)
      for(j=0;j<5;j++)
        if(max<a[i][j])
        max=a[i][j];
      return max;

}
main()
{
    int i,j;
    abc();
    for(i=0;i<2;i++)
      printf("%d ",average(i));

    printf("%d ",c());

    printf("%d",d());




}
