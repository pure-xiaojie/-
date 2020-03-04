/* Note:Your choice is C IDE */
#include <stdio.h>
int main()
{int a[1000];
    int n, k;
    while(2 == scanf("%d%d", &n, &k))
    {
        int i, j;
        for(i = 1; i <= n; ++i)
            a[i] = 1;
        for(i = 2; i <= k; ++i)
            for(j = 1; j * i <= n; ++j)
                a[i*j] ^= 1;
        for(i = 1; i <= n; ++i)
            if(a[i]) printf("%d ", i);
        putchar('\n');
    }
    return 0;}
