#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;

    char eat[105];
    int t  = 0,sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> eat[i];

    for (int i = 0; i < n; i++) {
        if(eat[i] == 'v') {
            t++;
        }
        else
            t = 0;

        if(t >= 3 ) {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
