#include<cstdio>
#include<iostream>

using namespace std;
long long dp[1000001][4];

int main()
{
    string ss;
    cin >> ss;
    dp[1][0] = dp[1][1] = 1;
    dp[0][2] = dp[0][3] = 0;
    int n = int(ss.size());
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = 1;
        for(int j = 1; j <= 3; j++)
        {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            if(ss[i-1] == ss[i-2] && j == 1)
                dp[i][j] -=1;
            else if(ss[i-1] == ss[i-2] && j == 2)
                dp[i][j] -= dp[i-2][1];
            else if(ss[i-1] == ss[i-2] && j == 3)
                dp[i][j] -= dp[i-2][2];

            if(i >= 3 && ss[i-1] == ss[i-3] &&ss[i-1] != ss[i-2] && j == 2)
                dp[i][j] -= 1;
            else if(i >= 3 && ss[i-1] == ss[i-3] &&ss[i-1] != ss[i-2] && j == 3)
                dp[i][j] -= dp[i-3][1];

            if(i >= 4 && ss[i-1] == ss[i-4] && ss[i-1]!= ss[i-2] && ss[i-1]!= ss[i-3] && j == 3)
                dp[i][j] -=1;
        }
        printf("%4d",dp[n][0] +dp[n][1] + dp[n][2] + dp[n][3]);
    }
    return 0;
}
