#include<cstdio>
#include<iostream>

using namespace std;

const int maxn=1005;
const int Max=0x3f3f3f3f;

int main()
{
    int n,m;
    cin>>n >>m;

    int a[maxn],j;
    int t=Max;

    memset(a,0,sizeof(a));
    for(int i=0; i<m; i++)
    {
        cin >> j;
        a[j]++;
    }
    for(int i=1; i<=n; i++)
        t=min(t,a[i]);

    cout << t << endl;
    return 0;
}
