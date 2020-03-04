#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > reconstructMatrix(int upper, int lower, vector<int>& colsum) {
    int len = colsum.size();
    int sum = 0;
    vector<vector<int> > res;
    vector<vector<int> > res1(2,vector<int>(len));
    for(int i = 0; i < len; i++) {
        sum += colsum[i];
    }

    if(sum != (upper + lower))
        return res;

    int u = upper,l = lower;

     for(int i = 0; i < len; i++) {
        if(colsum[i] == 2) {
            res1[0][i] = 1;
            res1[1][i] = 1;
            u--;
            l--;
        }
     }

    for(int i = 0; i < len; i++) {
        if(colsum[i] == 1 && res1[0][i] != 1) {
            if(u > 0) {
                res1[0][i] = 1;
                res1[1][i] = 0;
                u--;
            }
            else if(l > 0) {
              res1[0][i] = 0;
              res1[1][i] = 1;
              l--;
            }

        }
    }

    int up1 = 0,lo1 = 0;
    for(int i = 0; i < len; i++) {
        up1 += res1[0][i];
        lo1 += res1[1][i];
    }


    if(up1 == upper && lo1 == lower)
        return res1;
    else
        return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,m,s,x;
        vector<int> a;
        cin >> n >> m >> s;
        for(int i = 0; i < s; i++) {
            cin >> x;
            a.push_back(x);
        }
        vector<vector<int> > res = reconstructMatrix(n,m,a);

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

