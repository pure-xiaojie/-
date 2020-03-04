#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
    int year,n;
    cin >> year >> n;
    int sum = 0;
    while(year <= 3012)
    {
        int a,b,c,d;
        int num[10] = {0};
        a = year/1000;
        b = year%1000/100;
        c = year%100/10;
        d = year%10;
        num[a]++;
        num[b]++;
        num[c]++;
        num[d]++;
        int flag = 1;
        if(a == b && c == d || a == c && b == d || a == d &&
           b == c)
            flag = 0;
        if(*max_element(num,num+10) == 5-n && flag)
        {
            cout << sum << ' ' << a << b << c << d << endl;
            break;
        }
        else
        {
            sum++;
            year++;
        }
    }
    return 0;
}
