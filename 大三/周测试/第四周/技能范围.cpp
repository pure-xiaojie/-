#include<bits/stdc++.h>

using namespace std;
long long a[100005];
int dp[100005];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1; i <= n; i++) {
        scanf("%d",&a[i]);
        dp[i] = 1;
    }

    int sum = 0;
    for(int i = 1; i <= n; i++) {
       for(int j = i+1; j <= n  && j <= i+a[i]; j++) {
          if(a[i] >= a[j] )
             dp[j]++;
       }

       for(int j = i - 1; j >= 1 && j >= i-a[i]; j--) {
          if(a[i] >= a[j])
             dp[j]++;
       }
    }

    for(int i = 1; i <= n; i++) {
        //cout << dp[i] << " ";
        if(dp[i] >= k)
            sum++;
    }
    printf("%d",sum);
    return 0;
}
