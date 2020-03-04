#include <stdio.h>
#include<math.h>
int main()
{
 long int n,i,s=1;

    while(scanf("%d",&n)!=EOF)
    { for(i=2;i<=n;i++)
        s*=i;

      printf("%d\n",(int)log10((double)s)+1);
      s=1;
    }
return 0;
}



#include<stdio.h>
int main()
{
    long int n,i,s=1,m=0;
    while(scanf("%d",&n)!=EOF)
    {
      for(i=1;i<=n;i++)
        s*=i;
      for(;s;m++)
        s/=10;
      printf("%d\n",m);
      s=1;m=0;
    }
return 0;
}

