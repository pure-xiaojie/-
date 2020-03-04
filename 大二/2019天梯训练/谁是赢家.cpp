#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int x,y,z;
    cin >> x >> y >> z;
    int sum1 = 0,sum2 = 0;
    x ? sum2++ : sum1++;
    y ? sum2++ : sum1++;
    z ? sum2++ : sum1++;
    if(a > b && sum1 > 0 || sum1 == 3)
        printf("The winner is a: %d + %d",a,sum1);
    else
        printf("The winner is b: %d + %d",b,sum2);
    return 0;
}
