#include<bits/stdc++.h>

using namespace std;

int minPathSum(vector<vector<int> >& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int dp[m+1][n+1];

    dp[0][0] = grid[0][0];

    for(int i = 1; i < n; i++)
        dp[0][i] = dp[0][i-1] + grid[0][i];

    for(int i = 1; i < m; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];

    for (int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++)
            dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j];
    }
    return dp[m-1][n-1];
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int m,n;
        vector<vector<int> > grid;
        cin >> m >> n;
        for(int i = 0; i < m; i++) {
            int num;
            vector<int> a;
            for(int j = 0; j < n; j++) {
                cin >> num;
                a.push_back(num);
            }
            grid.push_back(a);
        }
        cout << minPathSum(grid) << endl;
    }
    return 0;
}
