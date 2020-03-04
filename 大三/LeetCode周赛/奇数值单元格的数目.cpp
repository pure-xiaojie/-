#include<bits/stdc++.h>

using namespace std;

int oddCells(int n, int m, vector<vector<int> >& indices) {
    vector<vector<int> > res;
    vector<int> k(m,0);

    for(int i = 0; i < n; i++) {
       res.push_back(k);
    }

    int len = indices.size();
    for (int i = 0; i < len; i++) {
        int x = indices[i][0], y = indices[i][1];

        for(int j = 0; j < m; j++)
            res[x][j] += 1;

        for(int j = 0; j < n; j++)
            res[j][y] += 1;
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if( res[i][j] % 2 == 1)
                sum++;
        }
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n,m,s;
        vector<vector<int> > indices;

        cin >> n >> m;
        for(int i = 0; i < 2; i++) {
            int x,y;
            vector<int> a;
            cin >> x >> y;
            a.push_back(x);
            a.push_back(y);

            indices.push_back(a);
        }
        cout << oddCells(n,m,indices) << endl;
    }
    return 0;
}
