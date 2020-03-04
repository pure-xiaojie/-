#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
long long num[1000005];

int main()
{
    int n;
    while(cin >> n,n) {
    for (int i = 0; i < n; i++)
        cin >> num[i];

    long long mid;
    if(n % 2 != 0)
        mid = num[n/2];
    else
        mid = (num[n/2] + num[n/2-1])/2;

    if(num[0] > num[n-1])
        printf("%lld %lld %lld\n",num[0],mid,num[n-1]);
    else
        printf("%lld %lld %lld\n",num[n-1],mid,num[0]);

   }
    return 0;
}
