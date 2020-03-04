#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct point
{
    int x, y, step;
} st;

queue <point> q;
int vis[200000];
int n, m;
int flat;

int bfs()
{
    while (!q.empty())
        q.pop();

    memset(vis, 0, sizeof(vis));
    vis[st.x] = 1;
    q.push(st);
    while (!q.empty())
    {
        point now = q.front();
        if(now.x==m)
            return now.step;
        q.pop();
        for (int j = 0; j < 3; j++)
        {
            point next = now;
            if (j == 0)
                next.x = next.x + 1;
            else if (j == 1)
                next.x = next.x - 1;
            else if (j == 2)
                next.x = next.x * 2;

            ++next.step;
            if (next.x == m)
                return next.step;
            if (next.x >= 0 && next.x <= 200000 && !vis[next.x])
            {
                vis[next.x] = 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d", &n,&m))
    {
        st.x = n;
        st.step=0;
        printf("%d\n", bfs());
    }
    return 0;
}
