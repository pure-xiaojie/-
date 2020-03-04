#include<bits/stdc++.h>

using namespace std;

vector<vector<int> >getRes(vector<vector<int> > & intervals)
{
    int n = intervals.size();
    vector<vector<int> > res;
    vector<int> starts,ends;
    for(int i = 0; i < n; i++) {
        starts.push_back(intervals[i][0]);
        ends.push_back(intervals[i][1]);
    }
    sort(starts.begin(),starts.end());
    sort(ends.begin(),ends.end());

    for(int  i = 0, j = 0; i < n; i++) {
        if(i == n-1 || starts[i+1] > ends[i]) {
            res.push_back({starts[j] , ends[i]});
            j = i + 1;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        int x,y;
        vector<vector<int> > num;
        cin >> x >> y;
        for(int i = 0; i < x; i++) {
            vector<int> s;
            int t;
            for(int j = 0; j < y; j++) {
                cin >> t;
                s.push_back(t);
            }
            num.push_back(s);
        }
        vector<vector<int> > res = getRes(num);
        for(int i = 0; i < res.size(); i++) {
            for(int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
