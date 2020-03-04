#include"stdio.h"
#include"math.h"
main()
{
    char a[200][10000];
    int m=1,i,j;
    while(~scanf("%s",a[m]))
       m++;

    for(i=2;i<m;i++)
    {
       for(j=2;j<=sqrt(i);j++)
        if(i%j==0)
          break;
        if(j>sqrt(i))
        printf("%s\n",a[i]);
    }


}
