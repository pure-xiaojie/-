#include<bits/stdc++.h>

using namespace std;
long long a[1000005];

int main() {
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int dp[n+1],res = 1;
    for(int  i = 0; i <= n; i++)
        dp[i]=1;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++)
            if(a[j] < a[i]) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        res = max(res,dp[i]);
        if(res >=3)
            break;
    }
    if(res >= 3)
        cout << "true";
    else
        cout << "false";
    return 0;
}
