#include<cstdio>
#include<iostream>

using namespace std;
#define maxi 100
#define maxj 500

int a[maxi][maxj];

int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n),n||m)
    {
        int judge = 0;
        for(int i = 0; i < m; i++)
        {
            int num = 0;
            for(int j = 0; j < n; j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j])
                num++;
            }
            if(num == n)
                judge = 1;
        }

        if(judge == 1)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}
