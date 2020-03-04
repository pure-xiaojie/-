#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
int res[1010];
int price[1010];

int main()
{
    int n,m;
    while(scanf("%d",&n),n) {
        for(int i = 0; i < n; i++)
            cin >> price[i];
        cin >> m;
        if(m < 5) {
            cout << m << endl;
            continue;
        }
        sort(price,price+n);
        memset(res,0,sizeof(res));
        m -= 5;
        for(int i = 0; i < n-1; i++)
        {
            for(int j = m; j >= price[i]; j--)
            {
                res[j] = max(res[j],res[j-price[i]]+price[i]);
            }
        }
        cout << 5+m-res[m]-price[n-1] << endl;
    }
    return 0;
}

