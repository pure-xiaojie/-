#include<stdio.h>
#include<iostream>
#include<algorithm>

#include<queue>
using namespace std;

#define max1 1000001
int a[max1];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,s,i;
        scanf("%d%d",&n,&s);
        a[0]=0;
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            a[i]=a[i]+a[i-1];
        }

        int ans = n+1,j=1;
        for(i=1; i<=n; i++)
        {
            if(a[j-1] > a[i]-s)
                continue;
            while(a[j-1] <= a[i]-s)
               j++;
            ans = min(ans, i-j+1);
        }
        printf("%d\n", ans==n+1?0:ans+1);

    }
    return 0;
}
