#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int lengthOfLI(vector<int>& nums)
{
    vector<int> res;
    for(int i = 0; i < nums.size(); i++) {
        vector<int>::iterator it = std::lower_bound(res.begin(),res.end(),nums[i]);
        if(it == res.end())
            res.push_back(nums[i]);
        else
            *it = nums[i];
    }
    return res.size();
}

int lengthOfLIS(vector<int>& nums)
{
    int len = nums.size();
    if(len < 2)
        return len;

    int res = 1;
    int dp[len+1];

    for(int  i = 0; i < len; i++)
        dp[i]=1;

    for(int i = 1; i < len; i++) {
        for(int j = 0; j < i; j++)
          if(nums[j] < nums[i]) {
            dp[i] = max(dp[i],dp[j]+1);
          }
        res = max(res,dp[i]);
    }
    return res;
}

int main()
{
    vector<int> nums;
    nums.push_back(10);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(7);
    nums.push_back(101);
    nums.push_back(18);
    cout << lengthOfLI(nums) << endl;
    return 0;
}
