#include"stdio.h"
main()
{
    long m,n,beauti[5]={6,28,496,8128,33550336};
    while(scanf("%ld%ld",&m,&n),m||n)
    {
       int i,t=0;
       for(i=0;i<5;i++)
         if(beauti[i]>=m&&beauti[i]<=n)
          {printf("%ld ",beauti[i]);t=1;}
       if(t==0)
          printf("No");
          putchar('\n');
    }
}
