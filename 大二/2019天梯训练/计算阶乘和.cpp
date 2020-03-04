#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,num[11];
    num[1] = 1;
    num[2] = 2;
    for(int i = 3; i < 11; i++)
        num[i] = num[i-1] * i;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += num[i];
    cout << sum;
    return 0;
}
