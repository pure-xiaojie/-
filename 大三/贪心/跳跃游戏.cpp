#include<bits/stdc++.h>

using namespace std;

bool canJump(vector<int>& nums) {
    int len = nums.size();
    int sum = 1;
    for (int i = len-2; i >= 0; i--) {
        if(nums[i] >= sum) {
            sum = 1;
        }
        else
            sum += 1;
        if(i == 0 && sum > 1)
            return false;
    }

    return true;
}

int main()
{
    int n;
    while(~scanf("%d",&n)) {
        vector<int> num;
        int m;
        for (int i = 0; i < n; i++) {
            cin >> m;
            num.push_back(m);
        }
        bool flag = canJump(num);
        cout << flag << endl;
    }
    return 0;
    return 0;
}
