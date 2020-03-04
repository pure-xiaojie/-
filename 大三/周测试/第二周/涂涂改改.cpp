#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    char a[2005];
    char ch[3][5] = {"DAY","AYD","YDA"};
    while(~scanf("%d%d",&n,&k)) {
        cin >> a;
        int minN = 2000;
        for(int i = 0; i <= n-k; i++) {
            for(int j = 0; j < 3; j++) {
                int sum = 0;
                for(int t = 0; t < k; t++) {
                    if(a[i+t] != ch[j][t%3])
                        sum++;
                }
                minN = min(minN,sum);
            }
        }
        cout << minN << endl;
    }
    return 0;
}
