#include<cstdio>
#include<iostream>

using namespace std;
long long sum = 0;

long long fun(int m)
{
   sum++;
   if(m == 1)
        return sum;
   else if(m%2 == 1)
        fun(m * 3 + 1);
   else
        fun(m/2);
}
int main()
{
    int n,m,n2,m2;
    while(~scanf("%d%d",&n,&m))
    {
        long long max = 0;
        long long count = 0;
        if(n > m)
           n2 = m,m2 = n;
        else
           n2 = n,m2 = m;
        for(int i = n2; i <= m2; i++)
        {
            count = fun(i);
            if(max < count)
                max = count;
            sum = 0;
        }
       printf("%d %d %lld\n",n,m,max);
    }

    return 0;
}
