#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
char map[10][10];
int t[10];
int sum;

void dfs(int row, int num)
{
    if(num == k)
        sum++;
    else if(row == n)
        return ;
    else
    {
        for(int i = 0; i < n; i++)
        {
            if(map[row][i] == '#' && !t[i])
            {
                t[i] = 1;
                dfs(row+1, num+1);
                t[i] = 0;
            }
        }
        dfs(row+1,num);
    }
}

int main()
{
    int i, j;
    while(scanf("%d%d", &n, &k))
    {
        if(n == -1 && k == -1)
            break;
        for(i = 0; i < n; i++)
            cin >> map[i];
        memset(t, 0, sizeof(t));
        sum = 0;
        dfs(0, 0);
        cout << sum << endl;
    }
    return 0;
}

