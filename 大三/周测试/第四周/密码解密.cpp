#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n)) {
        char ch[100];
        for(int i = 1; i <= n; i++)
            cin >> ch[i];
        if(n == 1)
            cout << ch[1] << endl;
        else {
            int nu[100],r = 0;
            for(int k = 1; k <= n/2; k++)
                if(n % k == 0)
                    nu[r++] = k;
            nu[r] = n;

            for(int i = 0; i <= r; i++) {
                int t = nu[i];
                for(int j = 1; j < t; j++,t--) {
                    char temp = ch[j];
                    ch[j] = ch[t];
                    ch[t] = temp;
                }
            }
        for(int i = 1; i <= n; i++)
            cout << ch[i];
        cout << endl;
        }

    }
    return 0;
}
