#include<bits/stdc++.h>

using namespace std;
long long dp[1000005];

int main()
{
    int n;
    while(~scanf("%d",&n)) {
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int coins[4] = {1,2,5,10};
        for(int i = 0; i <4; i++) {
            for (int j = coins[i]; j <= n; j++) {
                dp[j] = (dp[j] + dp[j-coins[i]]) % 1000000007;
            }
        }
        cout  << dp[n] << endl;
    }
    return 0;
}
