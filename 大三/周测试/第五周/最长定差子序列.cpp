#include<bits/stdc++.h>

using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    int len = arr.size();
    sort(arr.begin(),arr.end());
    int dp[len+1] = {0};

    for(int i = 0; i < len; i++)
        for()
}

int main()
{
    int n,t,m;
    cin >> n;
    while(n--) {
        vector<int> s;
        cin >> t;
        for(int i = 0; i < t; i++) {
            cin >> m;
            s.push_back(m);
        }
        int k;
        cin >> k;
        cout << longestSubsequence(s,k) << endl;
    }
    return 0;
}
