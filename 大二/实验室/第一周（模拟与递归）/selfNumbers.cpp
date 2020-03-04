#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
int a[10010];

int judge(int n)
{
    int i = n;
    while(n)
    {
        i += n%10;
        n /= 10;
    }
    return i;
}

int main()
{
    memset(a,0,sizeof(a));
    for(int i = 1; i < 10000; i++)
        a[judge(i)] = 1;
    for(int i = 1; i < 10000; i++)
        if(!a[i])
        printf("%d\n",i);

    return 0;
}
