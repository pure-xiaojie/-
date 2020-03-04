#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n),n != -1)
    {
        int a[11][2];
        for(int i = 0; i < n; i++)
            cin >> a[i][0] >> a[i][1];

        int sum = a[0][0]*a[0][1];
        for(int i = 1; i < n; i++)
        {
            sum += a[i][0] * (a[i][1] - a[i-1][1]);
        }
        cout << sum << " miles" << endl;
    }
    return 0;
}
