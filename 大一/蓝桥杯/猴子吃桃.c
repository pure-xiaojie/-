/* Note:Your choice is C IDE */
#include<stdio.h>
int main()
{int n,s=1;
  
while(scanf("%d",&n)!=EOF)
{for(;n>1;n--)
  s=(s+1)*2;
 printf("%d\n",s);
  
    s=1;
}
    return 0;
}
