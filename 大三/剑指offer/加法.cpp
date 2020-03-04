#include<bits/stdc++.h>

using namespace std;

int Add(int num1, int num2)
{
    int sum,n;
    while(num2 != 0) {
        sum = num1^num2;
        n = (num1&num2)<<1;
        num1 = sum;
        num2 = n;
    }
    return num1;
}

int main()
{
    cout << Add(14,5) << endl;
    return 0;
}
