#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
int num[10005];

void init()
{
    num[1] = 2,num[2] = 3;
    int k = 3;
    for(int i = 5; i; i+=2)
    {
        if(i % 2 == 0)
            continue;
        int j;
        for(j = 3; j <= sqrt(i); j++)
            if(i % j == 0)
                break;

        if(j > sqrt(i))
        {
            num[k]=i;
            k++;
            if(k > 10001)
                break;
        }


    }
}

int main()
{
    int n,m;
    init();
    scanf("%d%d",&n,&m);
    int t = 1;
    for(;n <= m; n++)
        if(t++ % 10 != 0)
            if(n != m)
                printf("%d ",num[n]);
            else
                printf("%d",num[n]);
        else
            printf("%d\n",num[n]);
    return 0;
}

