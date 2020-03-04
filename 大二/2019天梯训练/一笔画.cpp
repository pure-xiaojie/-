#include<cstdio>
#include<iostream>

using namespace std;
const int n = 3;
const int m = 5;
int ans = 0;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int vis[10][10];

void dfs(int x, int y,int cnt)
{
    if(x == 2 && y == 0 && cnt == 14)
    {
        ans++;
        return;
    }
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if(tx >= 0 && tx < n && ty >= 0 && ty < m && vis[tx][ty] == 0)
        {
            dfs(tx,ty,cnt+1);
        }
    }
    vis[x][y] = 0;
}
int main()
{
    dfs(0,0,0);
    cout << ans << endl;
    return 0;
}
