#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

struct node
{
    int n;
    friend bool operator<(node a,node b)
    {
        return a.n>b.n;
    }
} a;

int main()
{
    int T,t,n;
    priority_queue<node>q;

    while( ~scanf("%d%d",&T,&t))
    {
        while(T--)
        {
            char ch;
            cin >> ch;
            if( ch == 'I')
            {
                cin >> a.n;
                if(q.size() < t)
                    q.push(a);
                else
                {
                    q.push(a);
                    q.pop();
                }
            }
            else
                cout << q.top().n << endl;
        }
        while( !q.empty())
            q.pop();
    }

    return 0;
}

