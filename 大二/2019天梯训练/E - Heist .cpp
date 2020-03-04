#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    long long a[1005];
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a,a+n);
        int sum = 0;
        for(int i = 1; i < n; i++)
            if(a[i-1]+1 != a[i])
            sum+=a[i]-a[i-1]-1;
        cout << sum << endl;

    }
    return 0;
}
