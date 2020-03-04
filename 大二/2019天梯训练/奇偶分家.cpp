#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n,sum1 = 0,sum2 = 0;
    cin >> n;
    int m;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        if(m % 2 == 0)
            sum2++;
        else
            sum1++;
    }
    cout << sum1 << " " << sum2;
    return 0;
}
