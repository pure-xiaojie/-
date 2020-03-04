/* Note:Your choice is C IDE */
#include <stdio.h>
int main()
{
    double sum=0;
    long long int k,i;
    scanf("%d",&k);
    for(i=1;;i++)
    {
        sum=sum+1.0/i;
        if(sum>k)
            break;
    }
    printf("%lld",i);
    return 0;
}
