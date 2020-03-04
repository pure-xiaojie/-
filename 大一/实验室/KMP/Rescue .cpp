//����
#include<stdio.h>
#include<climits>
#define MAX 201

char map[MAX][MAX];
int vis[MAX][MAX];
int n,m,ax,ay,minx;

void dfs(int x,int y,int len)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return;
    if(len>=minx)
        return;
    if(map[x][y]=='#')
        return;
    if(vis[x][y]==1)
        return;
    if(map[x][y]=='r')
    {
        if(len<minx)
            minx=len;
        return;
    }
    if(map[x][y]=='x')
        len+=1;

    vis[x][y]=1;
    dfs(x+1,y,len+1);
    dfs(x-1,y,len+1);
    dfs(x,y+1,len+1);
    dfs(x,y-1,len+1);
    vis[x][y]=0;
}

int main()
{
    int i,j,len;
    while(~scanf("%d %d",&n,&m))
    {
        for(i=0; i<n; ++i)
        {
            for(j=0; j<m; ++j)
            {
                map[i][j]=getchar();
                if(map[i][j]=='a')
                {
                    ax = i;
                    ay = j;
                }
            }
            getchar();
        }
        len = 0;
        minx = INT_MAX;
        dfs(ax,ay,len);
        if(minx != INT_MAX)
            printf("%d\n",minx);
        else
            printf("Poor ANGEL has to stay in the prison all his life.\n");

    }

    return 0;
}
//�������
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#define N 201
using namespace std;

struct Persion
{
    int x,y;
    int time;
    friend bool operator < (const Persion &a,const Persion &b)
    {
        return a.time>b.time;
    }

};

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char map[N][N];
int visited[N][N];
int m,n;

int BFS(int x,int y)
{
    priority_queue <Persion>q;
    Persion current,next;
    memset(visited,0,sizeof(visited));

    current.x=x;
    current.y=y;
    current.time=0;
    visited[current.x][current.y]=1;
    q.push(current);

    while(!q.empty())
    {

        current=q.top();
        q.pop();
        for(int i=0;i<4;i++)
        {
            next.x=current.x+dir[i][0];
            next.y=current.y+dir[i][1];

            if(next.x>=0&&next.x<n&&next.y>=0&&next.y<m&&map[next.x][next.y]!='#'&&!visited[next.x][next.y])
            {

                if(map[next.x][next.y]=='r')
                    return current.time+1;



                if(map[next.x][next.y]=='x')
                    next.time=current.time+2;
                else
                    next.time=current.time+1;

                visited[next.x][next.y]=1;
                q.push(next);

            }
        }


    }

    return -1;
}

int main()
{
    int i,j;
    Persion angle;

    while(cin>>n>>m&&(m||n))
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='a')
                {
                    angle.x=i;
                    angle.y=j;
                }
            }
         int time=BFS(angle.x,angle.y);

         if(time==-1)
            cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
         else
            cout<<time<<endl;
    }
    return 0;
}

