#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
	int num;
	int id;
}s;

bool operator < (const node &x,const node &y)
{
	if(x.num==y.num)
	  return x.id>y.id;
	else
	  return x.num<y.num;
}

int main()
{
	int n,a,b;
	char str[5];
	while(scanf("%d",&n)!=EOF)
	{
		int k=1;
		priority_queue<node>q[4];
		while(n--)
		{
			scanf("%s%d",str,&a);
			if(strcmp(str,"IN")==0)
			{
				scanf("%d",&b);
				s.num=b;
				s.id=k++;
				q[a].push(s);
			}
			else
			{
				if(!q[a].empty())
				{
					s=q[a].top();
					q[a].pop();
					printf("%d\n",s.id);
				}
				else
				  printf("EMPTY\n");
			}
		}
	}
	return 0;
}
