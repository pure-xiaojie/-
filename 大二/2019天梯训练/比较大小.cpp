#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    int a[5];
    cin >> a[0] >> a[1] >> a[2];

    sort(a,a+3);

    printf("%d->%d->%d",a[0],a[1],a[2]);
    return 0;
}
