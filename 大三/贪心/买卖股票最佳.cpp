#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int sum = 0;
    for(vector<int>::iterator it = prices.begin(); it < prices.end();it++)
        if(*it < *(it+1))
            sum += *(it+1)-*it;
    return sum;

}

int main()
{
    int a[]={7,1,5,3,6,4};
    vector<int> c;
    for(int i = 0; i < 6; i++)
        c.push_back(a[i]);

    cout << maxProfit(c) << endl;
    return 0;
}
