#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int n, x, y;
char a[10],b[10];
queue<int> q;
stack<int> s;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> x;
        scanf("%s",a);
        if (a[2]=='F')
        {
            while(!q.empty())
                q.pop();
            while (x--)
            {
                scanf("%s", b);
                if (b[0]=='I')
                {
                    cin >> y;
                    q.push(y);
                }
                else
                {
                    if (q.empty())
                        cout << "None" << endl;
                    else
                    {
                        cout << q.front() << endl;
                        q.pop();
                    }
                }
            }
        }
        else
        {
            while(!s.empty())
                s.pop();
            while (x--)
            {
                scanf("%s", b);
                if (b[0]=='I')
                {
                    cin >> y;
                    s.push(y);
                }
                else
                {
                    if (s.empty())
                        cout << "None" << endl;
                    else
                    {
                        cout << s.top() << endl;
                        s.pop();
                    }
                }
            }
        }
    }
    return 0;
}
