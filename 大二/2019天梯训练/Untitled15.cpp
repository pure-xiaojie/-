#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
    double t;
    double x;
}a[100010];

bool cmp(node a,node b)
{
    return a.t<b.t;
}

int main()
{
    int t;
    cin >> t;
    int sum = 1;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i].t >> a[i].x;
        sort(a+1,a+1+n,cmp);
        double s = 0;
        for(int i=1; i<n; i++)
            s = max(s,abs(a[i+1].x-a[i].x)/(a[i+1].t-a[i].t));
        printf("Case #%d: %.2f\n",sum++,s);
    }
    return 0;
}
