#include<cstdio>
#include<iostream>

using namespace std;

int change(long long n)
{
    int num = 0;
    while(n)
    {
        if(n % 2 != 0)
           num++;
        n /= 2;
    }
    return num;
}

int s[100000000];

int main()
{
    long long a,b,c;
    int an,bn,cn;
    for(int i = 0; i < 100000000; i++)
        s[i] = change(i);

    while(~scanf("%lld%lld%lld",&a,&b,&c))
    {
        an = s[a];
        bn = s[b];
        cn = s[c];

        for(long long i = a+1; i; i++)
        {
            long long n = s[i];
            if( n >= b && n <= c)
            {
                printf("%lld\n",i);
                break;
            }

        }

    }
    return 0;
}
