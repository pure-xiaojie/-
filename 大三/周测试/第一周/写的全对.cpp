#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int m,n ,a[201];
    cin >> m;
    while(m--) {
        int left = 0, right = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];

            if(i!=0) {
                if(a[i]-a[i-1] == 1)
                    left++;
                else if(a[i-1]-a[i] == 1)
                    right++;
            }
        }


        if(n <= 3) {
            cout << "YES";
        } else {
            if(left >= n-2 || right >= n-2)
                cout << "YES";
            else
                cout << "NO";
        }

        if(m > 0)
            cout << endl;
    }
    return 0;
}
