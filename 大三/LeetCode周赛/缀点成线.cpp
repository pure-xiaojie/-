#include<bits/stdc++.h>

using namespace std;

bool checkStraightLine(vector<vector<int> >& coordinates) {
    int len = coordinates.size();
    double k;
    if(coordinates[0][0] != coordinates[1][0]) {
        k = (coordinates[1][1] - coordinates[0][1])*1.0/(coordinates[1][0] - coordinates[0][0]);

        for(int i = 2; i < len; i++) {
            if((coordinates[i][0] - coordinates[i-1][0]) != 0 && (coordinates[i][1] - coordinates[i-1][1])/(coordinates[i][0] - coordinates[i-1][0]) != k)
                return false;
        }
    }
    else {
      for(int i = 2; i < len; i++) {
            if((coordinates[i][0] != coordinates[0][0]))
                return false;
        }
    }
    return true;
}

int main()
{
    int n,m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<vector<int> > coordinates;
        cin >> m;
        for (int j = 0; j < m; j++) {
            vector<int> a;
            int x,y;
            cin >> x >> y;
            a.push_back(x);
            a.push_back(y);
            coordinates.push_back(a);
        }
        cout << checkStraightLine(coordinates) << endl;
    }
    return 0;
}
