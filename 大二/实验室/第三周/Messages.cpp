#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n,a,b,c,t;
    while(cin >> n >> a >> b >> c >> t)
    {
        int sum = 0,s;
        for(int i=0; i<n; i++)
        {
            cin >> s;
            sum += t-s;
        }
        cout << max((n*a),(n*a)+sum*(c-b)) << endl;
    }
    return 0;
}

