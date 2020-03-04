#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;
int a[10000];

int main()
{
    long long n,i = 3,j;
    cin >> n;
    a[0] = 2;
    int t = 1;
    for( ; i <= n; i++)
    {
        for(j = 2; j <= sqrt(i); j++)
          if(i % j == 0)
            break;
        if(j > sqrt(i))
            a[t++]=i;
    }
    int sum = 0;
    for(int i = 1; i < t; i++)
    {
        if(a[i] - a[i-1] == 2)
            sum++;
    }

    cout << sum;
    return 0;
}

