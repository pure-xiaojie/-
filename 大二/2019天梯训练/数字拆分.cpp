#include<cstdio>
#include<iostream>

using namespace std;
int f[100];

int main()
{
    int n;
    cin >> n;
    f[0] = 1;
    for(int i =1; i <= n; i++)
        for(int j = i; j <= n; j++)
    {
        f[j] += f[j-i];
    }
    cout << f[n] << endl;
    return 0;
}
