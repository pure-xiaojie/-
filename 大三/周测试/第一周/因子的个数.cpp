#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[400005],n;

int main()
{
    cin >> n;
    ll temp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0)
            temp = a[0];
        else
            temp = __gcd(temp,a[i]);

    }

    ll sum = 0;
    for (ll i = 1; i * i <= temp; i++) {
        if(temp % i == 0) {
            sum++;
            if(i * i != temp)
                sum++;
        }
    }

    cout << sum;

    return 0;
}
