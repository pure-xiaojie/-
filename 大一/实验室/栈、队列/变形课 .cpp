#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define maxn 1000

using namespace std;

char ch[maxn][maxn];
int n,F,use[maxn];

void dfs(int x)
{
    int l=strlen(ch[x]);
    if(ch[x][l-1]=='m')
    {
        F=1;
        return;
    }
    for(int j=0; j<n; j++)
    {
        if(ch[x][l-1]==ch[j][0]&&use[j]==0)
        {
            use[j]=1;
            dfs(j);
        }
    }
}
int main()
{
    while(~scanf("%s",ch[0]))
    {
        memset(use,0,sizeof(use));
        int i,flag=0;
        n=1;
        F=0;
        while(1)
        {
            cin >> ch[n];
            int l=strlen(ch[n]);
            if(ch[n][l-1]=='m')
                flag=1;
            if(ch[n][0]=='0')
                break;
            n++;
        }
        if(!flag)
            printf("No.\n");
        else
        {
            for(i=0; i<n; i++)
            {
                if(ch[i][0]=='b')
                    dfs(i);
            }
            if(F)
                printf("Yes.\n");
            else
                printf("No.\n");
        }
    }
    return 0;
}

