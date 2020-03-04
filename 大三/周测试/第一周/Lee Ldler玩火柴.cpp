#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int a[500];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(~scanf("%d",&n)) {
        n *= 4;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a+1,a+n+1);

        int flag = 1;

        int s = a[1] * a[n];
        int left = 1,right = n;
        while(left < right) {
            if(a[left] != a[left+1]) {
                flag = 0;
                break;
            }
            if(a[right] != a[right-1]) {
                flag = 0;
                break;
            }
            if(s != a[left] * a[right]) {
                flag = 0;
                break;
            }
            s = a[left] * a[right];
            left += 2;
            right -= 2;
        }
        if(flag == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
    return 0;
}
