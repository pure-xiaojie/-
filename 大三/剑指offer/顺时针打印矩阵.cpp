#include<bits/stdc++.h>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    int n = matrix.size();
    vector<int> res;
    if(n == 1) {
        res.push_back(matrix[0][0]);
        return res;
    }

    for(int i = 0; i < n/2; i++)
    {
        for(int j = i; j < n-i; j++)
            res.push_back(matrix[i][j]);

        for(int j = i+1; j < n - i; j++)
            res.push_back(matrix[j][n-i-1]);

        for(int j = n-i-2; j >= i; j--)
            res.push_back(matrix[n-i-1][j]);

        for(int j = n-i-2; j > i; j--)
            res.push_back(matrix[j][i]);
    }
    if(n % 2 != 0)
        res.push_back(matrix[n/2][n/2]);

    return res;
}

int main()
{
    int n,m,t;
    cin >> n;
    while(n--)
    {
        vector<vector<int> > s;
        vector<int> res;
        cin >> m;
        for (int j = 0; j < m; j++) {
            vector<int> a;
            for (int i = 0; i < m; i++) {
                cin >> t;
                a.push_back(t);
            }
            s.push_back(a);
        }
        res = printMatrix(s);

        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
