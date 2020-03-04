#include<bits/stdc++.h>

using namespace std;

int uniquePaths(int m, int n) {
    int dp[100][100];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    int n,m,t;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        cout << uniquePaths(m,n) << endl;
    }
    return 0;
}
