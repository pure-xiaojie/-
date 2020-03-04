#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums.size();
}

int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    cout << removeDuplicates(nums)  << endl;
    return 0;
}
