#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int n,k,res;
char chess[10][10];  //棋盘
int isTrue[10];      //记录是否存放棋子

void dfs(int x, int num)
{
    if(num == k)
    {
        res++;
        return;
    }
    if(x > n)
        return;

    for(int i = 1; i <= n; i++) {
        if(chess[x][i] == '#' && !isTrue[i])
        {
            isTrue[i] = 1;
            dfs(x+1,num+1);
            isTrue[i] = 0;
        }
    }
    dfs(x+1,num);
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        if(n == -1 && k == -1)
            return 0;
        memset(isTrue,0,sizeof(isTrue));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> chess[i][j];
            }
        }
        dfs(1,0);
        cout << res << endl;
        res = 0;
    }
    return 0;
}
