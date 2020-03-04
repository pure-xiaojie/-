#include"stdio.h"
main()
{
    int i=0,money,a[7]={100,50,20,10,5,2,1};
    scanf("%d",&money);
    for(i=0;i<7;i++)
    {
      int pice=money/a[i];
      printf("%d ",pice);
      money-=pice*a[i];

    }

}
