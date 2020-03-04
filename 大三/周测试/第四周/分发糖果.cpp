#include<bits/stdc++.h>

using namespace std;
int a[100005];

int main() {
    int n;
    while(~scanf("%d",&n)) {
        int mini = 10005;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if(mini < a[i])
                mini = a[i];
        }

        for(int i = 1; i <= n; i++)
            a[i] -= mini;

        int m = 1,sum = mini;
        while(m <= n) {
            int j;
            for(j = 1; j <= n; j++) {
                if(a[j] == 0 && a[j+1] != 0)
                    break;
            }
            for(int i = m; i < j; i++) {
                a[i] -= 1;
                sum++;
            }
            if(j < n)
                m = j+1;
        }
        cout << sum << endl;
    }
    return 0;
}
