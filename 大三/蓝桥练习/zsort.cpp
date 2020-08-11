#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
#define ll long long
ll num[1005];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++)
            cin >> num[i];
        sort(num,num+n);

        int k = (n % 2 == 1) ? n/2+1 : n/2;

        queue<int> r;
        queue<int> l;

        for(int i = 0; i < k; i++)
            l.push(num[i]);
        for(int i = n-1; i >= k; i--)
            r.push(num[i]);

        int m = 1;
        while(!l.empty() && !r.empty()) {
            if(m % 2) {
                cout << l.front() << ' ';
                l.pop();
                m++;
            } else {
                cout << r.front() << ' ';
                r.pop();
                m++;
            }
        }

        if(!l.empty()) {
            cout << l.front() << endl;
            l.pop();
        }

        if(!r.empty()) {
            cout << r.front() << endl;
            r.pop();
        }

    }
    return 0;
}
