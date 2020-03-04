#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,m;

int temp[10][12] = {   //temp[i][0]  指m的个位i的循环节的长度
    {1,0},
    {10,1,2,3,4,5,6,7,8,9,0},
    {5,2,4,6,8,0},
    {10,3,6,9,2,5,8,1,4,7,0},
    {5,4,8,2,6,0},
    {2,5,0},
    {5,6,2,8,4,0},
    {10,7,4,1,8,5,2,9,6,3,0},
    {5,8,6,4,2,0},
    {10,9,8,7,6,5,4,3,2,1,0}
};

int main()
{
    int q;
    cin >> q;
    //每个数累加上前面的数
    for(int i = 0; i < 10; i++)
    {
        for(int j = 2; j <= temp[i][0]; j++)
        {
            temp[i][j] += temp[i][j-1];
        }
    }
    while(q--) {
        cin >> n >> m;
        ll num = n/m;
        m = m % 10;


        ll sum = temp[m][temp[m][0]];  //一个循环节

        sum = sum * (num / temp[m][0]);
        num = num % temp[m][0];
        if(num)
            sum += temp[m][num];
        cout << sum << endl;
    }
    return 0;
}
