#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
long long n = 1;

int main()
{
    int x,t = 1;
    cin >> x;
    while(n)
    {
        if(n % x == 0)
        {
            printf("%lld %d",n/x,t);
            break;
        }
        else
        {
            n = n*10+1;
            t++;
        }
    }
    return 0;
}
