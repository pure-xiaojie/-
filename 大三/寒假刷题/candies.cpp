#include<cstdio>
#include<iostream>

using namespace std;
int num[200010], sum[2], del[2];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        sum[0] = sum[1] = del[0] = del[1] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> num[i];
            sum[i%2] += num[i];
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {
            del[(i-1)%2] += num[i-1];
            sum[i%2] -= num[i];
            if(sum[0] + del[1] == sum[1] + del[0])
                res++;
        }
        cout << res << endl;
    }
    return 0;
}
