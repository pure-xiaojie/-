#include<bits/stdc++.h>

using namespace std;
const int N = 10010;
int dp[105][N];

int main()
{
    int n,x,a[105];

    while(~scanf("%d%d",&n,&x)) {
        for (int i = 1; i <= n; i++)
        cin >> a[i];

        for (int i = 0; i <= x; i++)
            dp[0][i] = N;

        for (int i = 1; i <= n; i++) {
            for(int j = 0; j <= x; j++) {
                if(j <= a[i])
                    dp[i][j] = min(a[i],dp[i-1][j]);
                else
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
            }

        }
        cout << dp[n][x] << endl;
    }
    return 0;
}
