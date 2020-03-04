#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<vector<string> > ans;

bool isok(vector<int>& record, int row) {
    for(int i = 0; i < row; i++) {
        if(record[i] == record[row] || row-record[row] == i-record[i]
           || row+record[row] == i+record[i])
            return false;
    }
    return true;
}

void helper(int l, int n, vector<string>&temp, vector<int>& record) {
    if(l == n) {
        ans.push_back(temp);
        return;
    }
    for(int i = 0; i < n; i++) {
        record[l] = i;
        if(isok(record,l)) {
            temp[l][i]='Q';
            helper(l+1,n,temp,record);
            temp[l][i]='.';
        }
    }
}

void solveNQueens(int n) {
    string s = "";
    vector<int> record(n);
    for(int i = 0; i < n; i++) {
        s += '.';
    }
    vector<string> temp(n,s);
    helper(0,n,temp,record);
}

int main() {
    int n;
    cin >> n;
    solveNQueens(n);
    for(int i = 0; i < ans.size(); i++)
        for(int j = 0; j < n; j++)
            cout << ans[i][j] << endl;
    return 0;
}
