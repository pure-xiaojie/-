#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    int len = nums.size();
    if(len == 0)
        return 0;
    int res=nums[0], currMax = nums[0], currMin = nums[0],n,m;

    for(int i = 1; i < len; i++) {
        int x = nums[i];
        n = currMax * x;
        m = currMin * x;
        currMax = max(n ,max(m,x));
        currMin = min(n,min(m,x));
        cout << currMax << "   "  << currMin << endl;
        res = max(currMax,res);
    }
    return res;
}

void fun(vector<int>& nums) {
    int len = nums.size();
    int dp[2][2],res=nums[0];
    dp[0][1] = nums[0];
    dp[0][0] = nums[0];

    for(int i = 1; i < len; i++) {
        int x = i % 2;
        int y = (i-1) % 2;
        dp[x][0] = max(dp[y][0] * nums[i],max(dp[y][1] * nums[i],nums[i]));
        dp[x][1] = min(dp[y][0] * nums[i],min(dp[y][1] * nums[i],nums[i]));
        res = max(res,dp[x][0]);
    }
}

int main()
{
    vector<int> a;
    a.push_back(-1);
    a.push_back(-2);
    a.push_back(-9);
    a.push_back(-6);
    cout << maxProduct(a) << endl;
    return 0;
}
