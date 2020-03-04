/* Note:Your choice is C IDE */
#include "stdio.h"
main()
{
    int n,i=0,s=0,a[4];
    while(~scanf("%d",&n))
    {
        i=0;
        while(n!=0)
        {
            a[i++]=n%10;
            n/=10;
        }
        for(i=3; i>=0; i--)
        {
            printf("%d ",a[i]);
            s+=a[i];
        }
        printf("\n");
        if(s%2==0)
            puts("YES");
        else
            puts("NO");
        s=0;
    }
}
