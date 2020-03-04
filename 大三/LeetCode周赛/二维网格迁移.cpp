#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > shiftGrid(vector<vector<int> >& grid, int k) {
    int leni = grid.size();
    int lenj = grid[0].size();
    vector<vector<int> > res(leni,vector<int>(lenj,0));
    vector<int> s;

    for(int i = 0; i < leni; i++) {
        for(int j = 0; j < lenj; j++) {
            s.push_back(grid[i][j]);
        }
    }

    int len = s.size();
    k = k % len;

    int i = 0,j = 0;
    for(int t = len-k; t < len; t++) {
        if(j < lenj)
        {
          res[i][j] = s[t];
          j++;
        }
        if(j >= lenj && i < leni)
        {
            i++;
            j = 0;
        }
    }
    for(int t = 0; t < len - k; t++) {
        if(j < lenj)
        {
          res[i][j] = s[t];
          j++;
        }
        if(j >= lenj && i < leni)
        {
            i++;
            j = 0;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        vector<vector<int> > res;

        int j,k,m;
        cin >> j >> k;
        for (int i = 0; i < j; i++) {
            vector<int> s;
            for(int t = 0; t < k; t++) {
                cin >> m;
                s.push_back(m);
            }
            res.push_back(s);
        }
        int a;
        cin >> a;
        res = shiftGrid(res,a);
        for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    }
    return 0;
}
