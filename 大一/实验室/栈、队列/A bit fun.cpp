#include <cstdio>
#include <iostream>
using namespace std;

#define maxn 100001
int a[maxn];

int main()
{
    int t;
    cin >> t;
    int n,m,i,j,k,s;

    for(int p=1; p<=t; p++)
    {
        scanf("%d%d",&n,&m);
        int sum=0;
        for(i=0; i<n; i++)
            cin >> a[i];

        for(i=0; i<n; i++)
        {
            for(j=i; j<n; j++)
            {
                s=0;
                for(k=i; k<=j; k++)
                {
                    s=s|a[k];
                }
                if(s>=m)
                    break;
                else
                    sum++;

            }
        }
        printf("Case #%d: %d\n",p,sum);

    }
    return 0;
}
