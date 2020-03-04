/* Note:Your choice is C IDE */
#include"stdio.h"
#include"math.h"
int main()
{
    long long int a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c),a||b||c)
    {
        if(c-a<b && c-b<a && b-a<c)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
