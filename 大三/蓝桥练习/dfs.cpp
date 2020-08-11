#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
char chess[8][8];
int flag[8][8];

int k[2][2],isOk;

void dfs(int x,int y,int sum)
{
    if(x == k[1][0] && y == k[1][1] && sum%2 == 0) {
        isOk = 1;
        return;
    }
    if(x < 0 || x >= 8 || y < 0 || y >= 8)
        return;

    if(flag[x][y] == 1)
        return;
    flag[x][y] = 1;

    if(isOk)
        return;
    dfs(x-2,y-2,sum+1);
    dfs(x-2,y+2,sum+1);
    dfs(x+2,y-2,sum+1);
    dfs(x+2,y+2,sum+1);



}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        memset(flag,0,sizeof(flag));
        isOk = 0;

        for(int i = 0; i < 8; i++)
            cin >> chess[i];

        int m = 0;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(chess[i][j] == 'K') {
                    k[m][0] = i;
                    k[m][1] = j;
                    m++;
                }
                if(m == 2)
                    break;
            }
            if(m == 2)
                break;
        }

        dfs(k[0][0],k[0][1],0);

        if(isOk == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
