#include<cstdio>
#include<iostream>

using namespace std;
int res[13000];
int w[3500],v[3500];

int main()
{
    int n, m;
    while(~scanf("%d%d",&n,&m)) {
        for(int i = 0; i < n; i++)
            cin >> w[i] >> v[i];

        for(int i = 0; i < n; i++)
        {
            for(int j = m; j >= w[i]; j--)
            {
                res[j] = max(res[j],res[j-w[i]]+v[i]);
            }
        }
        cout << res[m] << endl;
    }
    return 0;
}
