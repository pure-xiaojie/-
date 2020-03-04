#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int rob(vector<int>& nums) {
    int len = nums.size();

    if(len == 0)
        return 0;
    if(len == 1)
        return nums[0];

    int dp[len][2];

    dp[0][0] = 0;
    dp[0][1] = nums[0];
    int res = 0;
    for(int i = 1; i < len; i++) {
        for(int j = 0; j < 2; j++) {
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = max(dp[i-1][0]+nums[i],dp[i-1][1]);
            res = max(res,max(dp[i][0],dp[i][1]));
        }
    }
    return res;
}

int main()
{
    vector<int> nums;

    int n;
    while(scanf("%d",&n),n)
    {
        nums.push_back(n);
    }

    cout << rob(nums) << endl;
    return 0;
}

