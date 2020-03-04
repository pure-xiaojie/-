#include<iostream>
#include <cstdio>
using namespace std;
char a[25][25];
int dir[4][2]=
{
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
int x,y,num;
bool YES(int x0,int y0)
{

    if(x0<y&&x0>=0&&y0>=0&&y0<x)
        return true;
    else
        return false;
}
void DFS(int x0,int y0)
{
    a[x0][y0]='#';
    num++;
    int xx,yy;
    for(int i=0; i<4; i++)
    {
        int xx=x0+dir[i][0];
        int yy=y0+dir[i][1];
        if(YES(xx,yy)&&a[xx][yy]=='.')
            DFS(xx,yy);
    }

}
int main()
{
    int i,j,di,dj;
    while (~scanf("%d%d",&x,&y))
    {
        getchar();
        if (x==0&&y==0) break;
        for (i=0; i<y; i++)
        {
            for (j=0; j<x; j++)
            {
                scanf("%c",&a[i][j]);
                if(a[i][j] == '@')
                {
                    di = i;
                    dj = j;
                }
            }
            getchar();
        }
        num=0;
        DFS(di,dj);
        cout<<num<<endl;

    }
    return 0;
}
