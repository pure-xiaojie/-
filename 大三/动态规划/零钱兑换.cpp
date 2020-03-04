#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    int maxn = amount + 1;
    vector<int> dp(amount+1,maxn);

    dp[0] = 0;
    for(int i = 1; i <= amount; i++) {
       for(int j = 0; j < coins.size(); j++)
        {
            if(coins[j] <= i) {
                dp[i] = min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }

    if(dp[amount] > amount)
        return -1;
    else
        return dp[amount];
}

int main()
{
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    int num = 11;
    cout << coinChange(coins,num) << endl;
    return 0;
}
