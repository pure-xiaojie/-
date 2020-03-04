#include<bits/stdc++.h>

using namespace std;
long long a[20005];

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k)) {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 != 0 && k != 1)
                k--;
            else if(k == 1)
                sum+=a[i] % 2;
        }
        if(sum % 2 == 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
