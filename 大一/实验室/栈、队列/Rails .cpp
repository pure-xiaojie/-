#include<cstdio>
#include<stack>
#include<iostream>
#include<algorithm>

using namespace std;
#define maxn 1001

int main()
{
    int n;
    while(cin >> n,n)
    {
        int a[maxn];
        while(cin >> a[0],a[0])
        {
            int i,k;
            for(i=1; i<n; i++)
               cin >> a[i];

            stack<int>s;

            for(i=1,k=0; i<=n; i++)
            {
                s.push(i);
                while(s.top()==a[k])
                {
                    if(!s.empty())
                    {
                        k++;
                        s.pop();
                    }
                    if(s.empty())
                        break;
                }
            }
            if(k==n)
                printf("Yes\n");
            else
                printf("No\n");
        }
        printf("\n");

    }
    return 0;
}
