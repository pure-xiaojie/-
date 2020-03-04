#include<bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int s = 1,m = 0;
    for(int i = n-1; i >= 0; i--) {
        s += digits[i] + m;
        digits[i] = s % 10;
        m = s / 10;
        s = 0;
    }


    vector<int> res1(n+1);
    vector<int> res2(n);

    if(m == 0) {
       for(int i = 0; i < n; i++) {
            res2[i] = digits[i];
       }
    }
    else {
       res1[0] = 1;
       for(int i = 1; i < n; i++) {
            res1[i] = digits[i-1];
       }
    }
    return m==1 ? res1 : res2;
}

int main()
{
    int n,m,num;
    cin >> n;
    while(n--){
        vector<int> nums;
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> num;
            nums.push_back(num);
        }

        vector<int> res = plusOne(nums);
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << ' ';
        cout << endl;
    }
    return 0;
}
