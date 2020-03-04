#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void dfs(vector<vector<int> >& grid,int i)
{
    grid[i][i] = 0;

    for(int k = 1; k < grid.size(); k++) {
      if(grid[k][i] == 1) {
        grid[k][i] = 0;
        grid[i][k] = 0;
        dfs(grid,k);
      }
    }

}

int numIslands(vector<vector<int> >& grid)
{
    int n = grid.size();
    if(n == 0)
        return 0;

    int coun = 0;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
        if(grid[i][j] == 1) {
            coun++;
            dfs(grid,i);
        }
    }
    return coun;

}

int main()
{
    vector<vector<int> > a;
    vector<int> b;
    int x,num;
    cin >> x;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < x; j++) {
            cin >> num;
            b.push_back(num);
        }
        a.push_back(b);
        b.clear();
    }
    cout << numIslands(a) << endl;
    return 0;
}

