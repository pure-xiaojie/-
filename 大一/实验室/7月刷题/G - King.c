#include "stdio.h"
int main()
{
    int i,j;
    char m;
    int n;
    scanf("%c%d",&m,&n);

    int sum=0;
      if(n+1<=8)
         sum++;
      if(n+1<=8&&m-1>='a')
         sum++;
      if(n+1<=8&&m+1<='h')
         sum++;

      if(n-1>=1)
         sum++;
      if(n-1>=1&&m-1>='a')
         sum++;
      if(n-1>=1&&m+1<='h')
         sum++;

      if(m-1>='a')
        sum++;
      if(m+1<='h')
        sum++;

      printf("%d",sum);
      getchar();

    return 0;
}
