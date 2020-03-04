/* Note:Your choice is C IDE */
#include "stdio.h"
int main()
{int t=0;
 long int n;
 while(scanf("%lld",&n)!=EOF)
    {t=n/2+n/3+n/5+n/30-n/6-n/10-n/15;
     printf("%d\n",t);
    }
 return 0;
}
