#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
const int maxn = 200005;
long long a[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int res = 1,j = 0,l = a[0];
        for(int i = 1; i < n; i++) {
            if(a[i] <= l*2)
                res = max(res,i-j+1);
            else
                j=i;
            l = a[i];
        }
        cout << res << endl;

    }
    return 0;
}
