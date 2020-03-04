#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int len = cost.size();

    int dp[len+1];
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i < len; i++)
        dp[i] = min(dp[i-1],dp[i-2])+cost[i];

    return min(dp[len-1],dp[len-2]);

}

int main()
{
    vector<int> cost;

    int n;
    while(cin >> n, n != 0) {
        cost.push_back(n);
    }
    cout << minCostClimbingStairs(cost);
    return 0;
}
