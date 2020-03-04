#include<cstdio>
#include<cstring>

using namespace std;
int dp[50010];

int max(int a, int b) {
    return a > b ? a : b;
}
int main()
{
    int n,m,num[105];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        int sum = 0;
        for(int i = 0; i < m; i++) {
            scanf("%d",&num[i]);
            sum += num[i];
        }
        memset(dp,0,sizeof(dp));
        for(int i = 0; i < m; i++) {
            for(int j = sum/2; j >= num[i]; j--) {
                dp[j] = max(dp[j],dp[j-num[i]]+num[i]);
            }
        }
        printf("%d\n",sum-dp[sum/2]*2);
    }
    return 0;
}
