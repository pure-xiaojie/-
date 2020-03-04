#include <stdio.h>
#include <stdlib.h>
int zxgb(int a,int b)
{
    int i;
    for(i=1;a*i%b;++i);
    return a*i;
}
int main()
{
    int a,b;
    printf("%d%d",&a,&b);
    if(a>b)
      printf("%d\n",zxgb(a,b));
    else
      printf("%d\n",zxgb(b,a));
    return 0;
}
