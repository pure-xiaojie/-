#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int fang[4][2]= {1,0,0,1,-1,0,0,-1};

int t[25][25];
char map[25][25];

int n,m;
int number;

int dfs(int a,int b)
{
    if(a>=0 && a<=m && b>=0 && b<=n)
    {
        if(map[a][b]=='#')
            return 0;
        else if(t[a][b]==1)
            return 0;

        else
        {
            t[a][b]=1;
            number++;
            int k;
            for(k=0; k<4; k++)
              dfs(a+fang[k][0],b+fang[k][1]);
        }

    }
    else
        return 0;
}

int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        memset(t,0,sizeof(t));
        number=0;
        memset(map,'#',sizeof(map));
        int i,j;
        int x,y;
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                cin >> map[i][j];
                if(map[i][j]=='@')
                {
                    x=i;
                    y=j;
                }

            }

        }
        dfs(x,y);
        cout << number << endl;
    }
  return 0;
}
