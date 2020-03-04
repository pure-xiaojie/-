#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int maxn= 0,minn = prices[0];
    for(int i = 1; i < prices.size(); i++) {
        maxn = max(maxn,prices[i]-minn);
        minn = min(minn,prices[i]);
    }
    return maxn;
}

int main()
{
    vector<int> a;
    a.push_back(7);
    a.push_back(6);
    a.push_back(5);
    a.push_back(4);
    cout << maxProfit(a) << endl;
    return 0;
}
