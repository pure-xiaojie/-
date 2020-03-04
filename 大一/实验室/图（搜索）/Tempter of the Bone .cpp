#include<stdio.h>
#include<string.h>
#include<math.h>

char mat[10][10];
int vis[10][10];
int n,m,t;
int xs,ys,xd,yd;
int flag;
int dir[4][2]={1,0,-1,0,0,-1,0,1};

void dfs(int x,int y,int time)
{
    if(x<0||x>=n||y<0||y>=m)
        return;
    if(mat[x][y]=='X' || vis[x][y]==1)
        return;
    vis[x][y]=1;
    if(x==xd&&y==yd&&time==t)
    {
        flag=1;
        return;
    }
    if(time==t&&(x!=xd||y!=yd))
        return;
    if(time>t)
        return;
    for(int i=0;i<4;i++)
    {
        int xt=x+dir[i][0];
        int yt=y+dir[i][1];
        if(xt<0||xt>=n||yt<0||yt>=m||mat[xt][yt]=='X'||vis[xt][yt]==1)
            continue;
        dfs(xt,yt,++time);
        vis[xt][yt]=0;
        time--;
        if(flag==1)
            return;
    }
}

int main()
{
    while(scanf("%d%d%d",&n,&m,&t)&&(n||m||t))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",mat[i]);
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='S')
                {
                    xs=i;
                    ys=j;
                }
                if(mat[i][j]=='D')
                {
                    xd=i;
                    yd=j;
                }
            }
        }
        int ms=fabs(xd-xs)+fabs(yd-ys);
        if(t<ms || (t-ms)%2)
        {
            printf("NO\n");
            continue;
        }
        flag=0;
        memset(vis,0,sizeof(vis));
        dfs(xs,ys,0);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
