#include<bits/stdc++.h>

using namespace std;

//贪心
int cutRope1(int number) {
    if(number == 2)
        return 1;
    if(number == 3)
        return 2;
    int a = number % 3;   //计算余数
    int b = number / 3;   //计算有多个3

    if(a == 0)          //余数为0时，所有3乘积即是结果；  例如9: 3*3*3
        return pow(3,b);
    else if(a == 1)     //余数为1时，应将1*3分解成2*2；    例如10: 3*3*2*2
        return pow(3,b-1) * 4;
    else if(a == 2)
        return pow(3,b) * 2;   //余数为2时，直接将结果*2； 例如11： 3*3*3*2
}

//动态规划
int cutRope2(int number) {
    int dp[65];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    int res = -1;
    for(int i = 4; i <= number; i++) {
        for(int j = 1; j <= i/2; j++) {         //计算1到i的一半,因为后一半计算的值相同
            res = max(res,dp[j]*dp[i-j]);       //比如dp[1]*dp[4-1]  和  dp[3]*dp[4-3]
        }
        dp[i] = res;
    }
    return dp[number];
}

int main()
{
    int n,m;
    cin >> n;
    while(n--) {
        cin >> m;
        cout << cutRope2(m) << endl;
    }
    return 0;
}
