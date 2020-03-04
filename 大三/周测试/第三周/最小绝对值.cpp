#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > minimumAbsDifference(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int> > res;
    vector<int> t;
    int minNum = 1000000;
    for(int i = 1; i < n; i++) {
        if((arr[i] - arr[i-1]) < minNum)
            minNum = arr[i] - arr[i-1];
    }

    for(int i = 1; i < n; i++) {
        if(arr[i] - arr[i-1] == minNum) {
            vector<int> a;
            a.push_back(arr[i-1]);
            a.push_back(arr[i]);
            res.push_back(a);
        }
    }
    return res;
}

int main()
{
    int n;
    while (~scanf("%d",&n)) {
        vector<int> num;
        int m;
        vector<vector<int> > res;
        for(int i = 0; i < n; i++) {
            cin >> m;
            num.push_back(m);

            res = minimumAbsDifference(num);
        }
        for(int i = 0; i < res.size(); i++) {
            for(int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
