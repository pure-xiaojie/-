/* Note:Your choice is C IDE */
#include<stdio.h>
int main()
{
    int m,g,s,b,i;
   
    while(scanf("%d",&m)!=EOF)
     {   
           g=m%10;
           s=m/10%10;
           b=m/100;
         for(i=0;i<b;i++)
           putchar('B');
         for(i=0;i<s;i++)
           putchar('S');
         for(i=1;i<=g;i++)
           printf("%d",i);
          putchar('\n');
         
    }
    return 0;
}
