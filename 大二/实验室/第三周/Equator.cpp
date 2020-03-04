#include<cstdio>
#include<iostream>

using namespace std;
int a[2000001];

int main()
{
    int n;
    while(cin >> n)
    {
        int i, sum1 = 0, sum2 = 0;
        for (i = 0; i<n; i++)
        {
            cin >> a[i];
            sum1 = sum1 + a[i];
        }
        for (i = 0; i<n; i++)
        {
            if (sum2 * 2 < sum1)
                sum2 = sum2 + a[i];
            else
                break;
        }
       cout << i << endl;
    }

    return 0;
}

