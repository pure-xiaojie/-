#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int dp[100];

int sumRange(int i, int j) {
    if(i == 0)
        return dp[j];
    else
        return dp[j] - dp[i-1];
}

void NumArray(vector<int>& nums) {
    int len = nums.size();
    dp[0] = nums[0];
    for(int i = 1; i < len; i++)
        dp[i] = dp[i-1] + nums[i];
}

int main()
{
    vector<int> nums;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        nums.push_back(m);
    }
    NumArray(nums);
    cout << sumRange(0,2) << endl;
    cout << sumRange(2,5) << endl;
    cout << sumRange(0,5) << endl;
    return 0;
}
