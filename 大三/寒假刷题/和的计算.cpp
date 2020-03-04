#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            int m, x, y, res = 0;
            cin >> m;
            while(m--) {
                cin >> x >> y;
                res += x * y;
            }
            cout << res << endl;
        }
    }
    return 0;
}
