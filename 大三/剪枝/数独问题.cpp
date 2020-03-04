#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

bool isok(char board[9][9],int row, int col, char c) {
    for(int i = 0; i < 9; i++) {
        if(board[i][col] == c || board[row][i] == c)
            return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == c)
            return false;
    }
    return true;
}

bool solve(char board[9][9]) {
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++) {
           if(board[i][j] == '.') {
            for(char c = '1'; c <= '9'; c++) {
                if(isok(board,i,j,c)) {
                    board[i][j] = c;
                    if(solve(board))
                        return true;
                    else
                        board[i][j] = '.';
                }
            }
            return false;
           }
        }
        return true;
}
int main()
{
    char a[9][9]={
  {'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}
};
    cout << solve(a) << endl;
    return 0;
}
