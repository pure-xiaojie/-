#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;
#define type long long
queue<int> s;

void del(int k)
{
    int i=1;
    while(s.front()!=0)
    {
        if(i%k!=0)
            s.push(s.front());
        s.pop();
        i++;
    }
    s.pop();
    s.push(0);
}

int main()
{
    int t,n,i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1; i<=n; i++)
            s.push(i);
        s.push(0);
        i=1;
        while(s.size() > 4)
        {
            if(i%2 != 0)
                del(2);
            else
                del(3);
            i++;

        }
        i=0;
        while(!s.empty())
        {
            if(s.front())
            {
                if(i)
                   cout<<" ";

                cout<<s.front();
                i=1;

            }
            s.pop();
        }
        cout<<endl;
    }
return 0;
}
