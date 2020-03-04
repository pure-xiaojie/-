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
    if(i < 0 || i >= x || j < 0 || j >= y || grid[i][j] != 'O' || grid[i][j] == 'Y')
        return;
    grid[i][j] = 'Y';

    for(int k = 0; k < 4; k++)
        dfs(grid,i+dx[k],j+dy[k]);

}

void solve(vector<vector<char> >& board) {
    int n = board.size();
    int m = board[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i == 0 || j == 0 || i == n-1 || j == m-1)
                if(board[i][j] == 'O')
                    dfs(board,i,j);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            if(board[i][j] == 'Y')
                board[i][j] = 'O';
            cout << board[i][j];
        }
        cout << endl;
    }
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
   solve(a);
    return 0;
}

