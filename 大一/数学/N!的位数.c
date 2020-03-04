#include<stdio.h>
#include<math.h>
#define M 2.71828182846
#define PAI 3.141592654

int main()
{
    int n,sum;
    while(~scanf("%d",&n))
    {
      sum=log10(2*PAI*n)/2+n*log10(n/M)+1;

      if(n>3)
        printf("%d\n",sum);
      else
        printf("%d\n",1);
    }

 return 0;
}
