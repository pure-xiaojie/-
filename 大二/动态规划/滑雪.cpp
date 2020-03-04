#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int dp[110][110],a[110][110];
int arror[4][2] = {1,0,-1,0,0,1,0,-1};
int r,c,sum;

int dfs(int x,int y)
{
    int i,j,arrx,arry;
    if(!dp[x][y])
    {
        for(i = 0; i < 4; i++)
        {
            arrx = x + arror[i][0];
            arry = y + arror[i][1];
            if(arrx >= 0 && arrx < r &&
               arry >= 0 && arry < c &&
               a[arrx][arry] < a[x][y])
            {
                dp[x][y] = max(dp[x][y],dfs(arrx,arry));
            }
        }
        ++dp[x][y];
    }
    return dp[x][y];
}
int main()
{
    while(~scanf("%d%d",&r,&c))
    {
        sum = 0;
        int i,j;
        for(i = 0; i < r; i++)
            for(j = 0; j < c; j++)
            scanf("%d",&a[i][j]);

        memset(dp,0,sizeof(dp));

        for(i = 0; i < r; i++)
            for(j = 0; j < c; j++)
            sum = max(sum,dfs(i,j));

        printf("%d\n",sum);
    }
    return 0;
}
