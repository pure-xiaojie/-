#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n,n != -1)
    {
        long long c=1,x=0,t;
        for(int i = 0; i < n; i++)
        {
            t = c;
            c = x + 1;
            x = t + x;
        }
        cout << x << ' ' << x + c << endl;
    }
    return 0;
}
