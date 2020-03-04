#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;
typedef long long ll;
ll res[205];

ll dfs(int n)
{
    queue<ll> q;
    q.push(1);
    while(!q.empty())
    {
        ll m = q.front();
        q.pop();
        if(m % n == 0)
        {
            return m;
        }
        q.push(m*10);
        q.push(m*10+1);
    }
    return -1;
}

int main()
{
    int n;
    while(scanf("%d",&n), n != 0)
    {

        printf("%lld\n",dfs(n));
    }
    return 0;
}
