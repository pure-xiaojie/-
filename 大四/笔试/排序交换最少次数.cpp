#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> data[i];
        nums[i] = data[i];
    }

    sort(nums.begin(),nums.end());

    int counts = 0;

    for(int i = n-1, j = n-1; i >= 0; i--) {
        if(nums[j] == data[i]) {
            counts++;
            j--;
        }
    }


    cout << n-counts << endl;

    return 0;
}
