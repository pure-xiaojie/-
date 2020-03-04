#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<algorithm>

#define max(a,b) a > b ? a : b
#define N 100005

using namespace std;

int q[N]= {-1},w[N];
int main()
{
    int n,h;
    while(cin >> n,n)
    {
        int top = 0;
        __int64 ans = 0;
        for(int i=1; i<=n+1; i++)
        {
            if(i != n+1)
                cin >> h;
            else
                h = 0;
            if(h > q[top])
                q[++top] = h , w[top] = 1;
            else
            {
                __int64 cnt = 0;
                while(h <= q[top])
                {
                    ans = max(ans ,(cnt+w[top])*q[top] );
                    cnt += w[top--];
                }
                q[++top] = h;
                w[top] = cnt+1;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

