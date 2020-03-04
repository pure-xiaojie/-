#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    long long c1,c2,sum;
    scanf("%lld%lld",&c1,&c2);

    sum = ((c2 -c1)/100.0 + 0.5);

    int h = sum/3600;
    int m = sum%3600/60;
    int s = sum%3600%60;

    printf("%d%d:%d%d:%d%d",h/10,h%10,m/10,m%10,s/10,s%10);
    return 0;
}
