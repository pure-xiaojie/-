#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
     vector<vector<int> > res;
     int low = 1,high = 2;
     while(low < high) {
        int s = (low + high) * (high-low+1)/2;
        if(s == sum) {
            vector<int> s;
            for(int i = low; i <= high; i++) {
                s.push_back(i);
            }
            res.push_back(s);
            low++;
        }
        else if(s < sum) {
            high++;
        }
        else if(s > sum) {
            low++;
        }
     }
     return res;
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        int m;
        vector<vector<int> > res;

        cin >> m;
        res = FindContinuousSequence(m);
        for(int i = 0; i < res.size(); i++) {
            for(int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
