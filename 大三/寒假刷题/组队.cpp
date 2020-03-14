#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        int res = min(a,min(b,(a+b+c)/3));
        cout << res << endl;
    }
    return 0;
}
