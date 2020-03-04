#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int x;
    cin >> x;
    if(x == 10)
        printf("f(%.1f) = %.1f",x*1.0,1.0/x);
    else
        printf("f(%.1f) = %.1f",x*1.0,1.0*x);
    return 0;
}

