#include<iostream>
#include<cstring>
#include<cstdio>

char a[101][101];
int row,col;
int dir[8][2]=
{
    {1,0},
    {1,1},
    {1,-1},
    {0,-1},
    {0,1},
    {-1,0},
    {-1,1},
    {-1,-1}
};
using namespace std;

void dfs(int i,int j)
{
    a[i][j]='*';
    for (int k=0;k<8;k++)
    {
        int x=i+dir[k][0];
        int y=j+dir[k][1];
        if (x>=0&&x<=row-1&&y>=0&&y<=col-1&&a[x][y]=='@')
            dfs(x,y);
    }
    return;
}
int main()
{
    while (scanf("%d%d",&row,&col),row&&col)
    {
        int c=0;
        getchar();
        int i,j;
        for (i=0; i<row; i++)
            for (j=0; j<col; j++)
            cin>>a[i][j];

        for (i=0; i<row; i++)
            for (j=0; j<col; j++)
            if (a[i][j]=='@')
            {
                dfs(i,j);
                c++;
            }
        printf("%d\n",c);
    }
    return 0;
}
