#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;
long long m;

int judge()
{
    long long i;
    for(i = 2; i <= sqrt(m); i++)
        if(m % i == 0)
            return 0;
    if(i > sqrt(m))
        return 1;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld",&m);
        if(judge() && m != 1)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
