/* Note:Your choice is C IDE */
#include <stdio.h>
int s[21][21] = {0};
int fun(int a, int b)
{
    if (a == b || 0 == b)    
     return s[a][b] = 1;
    if (s[a][b])    
     return s[a][b];
    return s[a][b] = fun(a - 1, b - 1) + fun(a - 1, b);
}

int main()
{
    int N;
    int m, n;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d%d", &m, &n);
        if (m > n / 2) m = n - m;
        printf("%d\n", fun(n, m));
    }
    return 0;
}