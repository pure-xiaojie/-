#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 5)
        cout << 7;
    else
        cout << (n+2)%7;
    return 0;
}
