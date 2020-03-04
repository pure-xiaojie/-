#include<bits/stdc++.h>

using namespace std;

int maximumSum(vector<int>& arr) {
    int len = arr.size();

    int mx = arr[0];
    for(int i = 1; i < len; i++)
        mx = max(mx,arr[i]);

    if(mx <= 0)
        return mx;

    vector<int> pre,rep;
    int sum1 = 0;
    for (int i = 0; i < len; i++) {
        pre.push_back(max(sum1,0));
        if(sum1 <= 0)
            sum1 = arr[i];
        else
            sum1 += arr[i];
    }

    int sum2 = 0;
    for (int i = len-1; i >= 0; i--) {
        rep.push_back(max(sum2,0));
        if(sum2 <= 0)
            sum2 = arr[i];
        else
            sum2 += arr[i];
    }

    for (int i = 0; i < len; i++) {
        mx = max(mx,pre[i]+rep[len-i-1]);
    }
    return mx;
}

int main()
{
    int t = 5;
    while(t--) {
        vector<int> s;
        int n,m;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> m;
            s.push_back(m);
        }
        cout << maximumSum(s) << endl;
    }
    return 0;
}
