#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

#define maxn 1000
char a[maxn][maxn];

void dfs (int n, int x, int y)
{
    if (n == 1)
    {
        a[x][y] = 'X';
        return ;
    }
    int m = (int)pow(3, double(n-2));
    dfs (n-1, x, y);
    dfs (n-1, x, y+2*m);
    dfs (n-1, x+m, y+m);
    dfs (n-1, x+2*m, y);
    dfs (n-1, x+2*m, y+2*m);
}

int main ()
{
    int i, j, n;
    while (scanf ("%d", &n), n != -1)
    {
        int m = (int)pow(3,double(n-1));
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
                a[i][j] = ' ';
            a[i][m] = '\0';
        }
        dfs (n, 0, 0);
        for (i = 0; i < m; i++)
            puts(a[i]);
            printf ("-\n");
    }
    return 0;
}

