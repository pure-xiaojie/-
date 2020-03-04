#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
const int maxn=200005;
int dp[maxn];
int v[maxn];

int a[7];

int main()
{
    int t = 1;
    while(cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6])
    {
        int sum = 0;
        for(int i = 1; i < 7; i++)
            sum += a[i]*i;
        if(sum == 0)
            break;

        if(sum % 2 == 1) {
            printf("Collection #%d:\nCan't be divided.\n\n",t++);
            continue;
        }
        memset(dp,0,sizeof(dp));
        memset(v,0,sizeof(v));
        int x = 1;
        for(int i = 1; i < 7; i++){
            for(int j = 1; j <= a[i]; j*=2) {
                v[x++] = j*i;
                a[i] -= j;
            }
            if(a[i] > 0)
                v[x++] = a[i]*i;
        }

        for(int i = 1; i <= x; i++)
            for(int k = sum/2; k >= v[i]; k--)
                dp[k] = max(dp[k],dp[k-v[i]]+v[i]);

        if(dp[sum/2] == sum/2)
            printf("Collection #%d:\nCan be divided.\n\n",t++);
        else
            printf("Collection #%d:\nCan't be divided.\n\n",t++);
    }
    return 0;
}
