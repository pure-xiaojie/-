#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int a[105];

int main()
{
    int n,t,i;
    while(scanf("%d",&n) != EOF)
    {
        memset(a,0,sizeof(a));
        for(i = 1; i <= n; i++)
        {
            scanf("%d",&t);
            a[t]++;
        }

        for(i = 1; i <= 100; i++)
        {
            if(a[i] == 1)
            {
                printf("%d\n",i);
                break;
            }

        }

    }
    return 0;
}
