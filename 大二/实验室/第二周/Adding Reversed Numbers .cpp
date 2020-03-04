#include<cstdio>
#include<iostream>

using namespace std;

int inverse_number(long long num)
{
    long long sum = 0;
    while(num)
    {
       sum = sum * 10 + num % 10;
       num /= 10;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        long long a,b;
        cin >> a >> b;
        a = inverse_number(a);
        b = inverse_number(b);
        cout << inverse_number(a + b) << endl;

    }
    return 0;
}
