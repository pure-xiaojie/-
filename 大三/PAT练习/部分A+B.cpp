#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int p(long long n,int dn)
{
   int sum = 0;
   while(n)
   {
       int t = n % 10;
       if(t == dn)
          sum = sum * 10 + t;
       n /= 10;
   }
   return sum;
}

int main()
{
    long long a,b;
    int da,db;
    scanf("%lld%d%lld%d",&a,&da,&b,&db);

    printf("%d",p(a,da)+p(b,db));
    return 0;
}
