#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int x,y;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void dfs(vector<vector<char> >& grid,int i,int j)
{
    if(i < 0 || i >= x || j < 0 || j >= y || grid[i][j] != '1')
        return;
    grid[i][j] = '0';

    for(int k = 0; k < 4; k++)
        dfs(grid,i+dx[k],j+dy[k]);

}

int numIslands(vector<vector<char> >& grid)
{
    int n = grid.size();
    if(n == 0)
        return 0;

    int m = grid[0].size();
    int coun = 0;

    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
        if(grid[i][j] == '1') {
            coun++;
            dfs(grid,i,j);
        }
    }
    return coun;

}

int main()
{
    vector<vector<char> > a;
    vector<char> b;
    char ch;
    cin >> x >> y;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            cin >> ch;
            b.push_back(ch);
        }
        a.push_back(b);
        b.clear();
    }
    cout << numIslands(a) << endl;
    return 0;
}
