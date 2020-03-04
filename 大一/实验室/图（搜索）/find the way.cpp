#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f   //×î´óÊý
int sx1,sy1,sx2,sy2,ex,ey,m,n;
char map[200][200];
int book[200][200];
int ans[200][200]={0};
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
struct node
{
	int x;
	int y;
	int s;
};
void bfs(int sx,int sy)
{
	node now,next;
	queue<node> q;
	now.x=sx;
	now.y=sy;
	now.s=0;
	book[sx][sy]=1;
	q.push(now);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			if(next.x<0 || next.x>=n || next.y<0 ||next.y>=m)
                continue;
			if(book[next.x][next.y]==0 && map[next.x][next.y]!='#')
			{
				book[next.x][next.y]=1;
				next.s=now.s+1;
				q.push(next);
				if(map[next.x][next.y]=='@')
				ans[next.x][next.y]=ans[next.x][next.y]+(next.s*11);
			}
		}
	}
	return ;
}
int main()
{
    int i,j;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
		{
				scanf(" %c",&map[i][j]);
				if(map[i][j]=='Y')
				sx1=i,sy1=j;
				if(map[i][j]=='M')
				sx2=i,sy2=j;
		}
		memset(book,0,sizeof(book));
		bfs(sx1,sy1);
		memset(book,0,sizeof(book));
		bfs(sx2,sy2);
		int res=INF;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			{
				if(ans[i][j]!=0 && ans[i][j]<res)
				res=ans[i][j];
			}
			printf("%d\n",res);
		memset(ans,0,sizeof(ans));
	}
	return 0;
}
