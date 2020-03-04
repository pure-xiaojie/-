#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n = 2000;
    while(n)
    {
        if(n%5 == 1 && n % 6 == 5 && n % 7 == 4 && n % 11 == 10)
        {
            cout << n;
            break;
        }
        else
            n++;
    }
    return 0;
}
