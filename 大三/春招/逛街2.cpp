#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int w[n],v[n];
    for(int i = 0; i < n; i++) {
        cin  >> w[i];
    }

    for(int i = 0; i < n; i++) {
        if(i == 0 || i == n-1)
            v[i] = 2;
        else
            v[i] = 3;

        int t = i + 1;
        for(int r = t+1; r < n; r++) {
            if(w[r] > w[t]) {
                v[i] += 1;
                t = r;
            }
        }
        t = i - 1;
        for(int l = t-1; l >= 0; l--) {
            if(w[l] > w[t]) {
               v[i] += 1;
               t = l;
            }

        }
    }

    for(int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    return 0;
}

