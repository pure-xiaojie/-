#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    ll a[105];
    while(~scanf("%d",&n)) {
        int min1 = 0,min2 = 0;
        for(int i = 0; i < n; i++) {
           cin >> a[i];
           if(a[i] & 1)
              min1++;
           else
              min2++;
        }
        cout << min(min1,min2) << endl;
    }
    return 0;
}
