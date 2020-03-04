#include<cstdio>
#include<iostream>
#include<string.h>

using namespace std;
int res[1005];
int energy[1005],sell[1005];

int main()
{
    int m;
    cin >> m;
    while(m--) {
        int n,v;
        cin >> n >> v;
        memset(res,0,sizeof(res));
        for(int j = 0; j < n; j++) {
            cin >> energy[j];
        }
        for(int j = 0; j < n; j++) {
            cin >> sell[j];
        }

        for(int j = 0; j < n; j++) {
            for(int k = v; k >= sell[j]; k--) {
                res[k] = max(res[k],res[k-sell[j]]+energy[j]);
            }
        }
        cout << res[v] << endl;

    }
    return 0;
}
