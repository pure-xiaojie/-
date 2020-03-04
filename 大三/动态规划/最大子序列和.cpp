#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    int dp = nums[0];
    int res = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        dp = max(dp+nums[i],nums[i]);
        res = max(res,dp);
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

    cout << maxSubArray(nums) << endl;
    return 0;
}
