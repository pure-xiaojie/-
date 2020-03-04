#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

const int maxn = 1e5+10;
int n,k,m;

struct node
{
    string s;
    long long cost;
    bool operator < (const node &other)const
    {
        return cost > other.cost;
    }
} word[maxn];

priority_queue<node> q[maxn];
map<string,int> group;

int main()
{
    while(cin >> n >> k >> m)
    {
        for(int i = 1; i <= n; i++)
        {
            cin >> word[i].s;
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> word[i].cost;
        }
        for(int i = 1; i <= k; i++)
        {
            int num;
            cin >> num;
            while(num--)
            {
                int x;
                cin >> x;
                group[word[x].s] = i;
                q[i].push(word[x]);
            }
        }
        long long ans = 0LL;
        for(int i = 0; i < m; i++)
        {
            string s;
            cin >> s;
            int id = group[s];
            node tmp = q[id].top();
            ans += tmp.cost;
        }
        cout << ans << endl;
    }

    return 0;

}

