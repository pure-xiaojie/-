#include<cstdio>
#include<iostream>

using namespace std;
int dp[50005];

int numTimesAllBlue(vector<int>& light) {
    int maxn = 1, res = 0;
    for(int i = 0; i < light.size(); i++) {
        maxn = max(light[i],maxn);
        if(maxn == i+1)
            res++;
    }
    return res;
}

int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        vector<int> light(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> m;
            light.push_back(m);
        }
        cout << numTimesAllBlue(light) << endl;
    }
    return 0;
}
