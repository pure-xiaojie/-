#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;
int vis[21];
int map[20][20];
int sum, n;
void dfs(int k, int num,int time)
{
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0 &&map[k][i]>=time)
		{
			vis[i]=1;
			dfs(i,num+1,map[k][i]);
			vis[i]=0;
		}

	}
	if(sum < num)
	   sum=num;
}
int main()
{
    int i,j;
	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cin>>map[i][j];
		}
		memset(vis,0,sizeof(vis));
		sum=0;
		vis[0]=1;
		dfs(0,1,0);
		cout<<sum<<endl;
	}
	return 0;
}
