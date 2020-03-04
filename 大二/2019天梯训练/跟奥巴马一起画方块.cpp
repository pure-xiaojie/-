#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;
    for(int i = 0; i < round(n/2.0); i++)
    {
         for(int j = 0; j < n; j++)
            cout << c;
         cout << endl;
    }
    return 0;
}
