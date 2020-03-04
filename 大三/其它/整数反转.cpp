#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int maxn = 0x7fffffff, minn = 0x80000000;
    long sum = 0;
    int x;
    cin >> x;
    while(x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    if(sum > maxn || sum < minn)
        cout <<  0 << endl;
    else
        cout << sum;
    return 0;
}
