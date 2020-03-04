#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
#define maxt 1001

int main()
{
    int t, kase = 0;
    while(cin >> t && t)
    {
        printf("Scenario #%d\n", ++kase);

        map<int , int> team;
        for(int i = 0; i < t; i++)
        {
            int n,x;
            cin >> n;
            while(n--)
            {
                cin >> x;
                team[x] = i;
            }
        }

        queue<int> q, q2[maxt];
        while(1)
        {
            int x;
            char cmd[10];
            cin >> cmd;
            if(cmd[0] == 'S')
                break;
            else if(cmd[0] == 'D')
            {
                int t = q.front();
                printf("%d\n",q2[t].front());

                q2[t].pop();
                if(q2[t].empty())
                    q.pop();
            }
            else if(cmd[0] == 'E')
            {
                cin >> x;
                int t = team[x];
                if(q2[t].empty())
                    q.push(t);
                q2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
}
