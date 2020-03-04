#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k,a[105];
    while(~scanf("%d%d",&n,&k)) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int sum = 0,i;
        for(i = 0; i < n; i++) {
            if(a[i] <= k)
                sum++;
            else
                break;
        }
        for(int j = n-1; j > i; j--)
            if(a[j] <= k)
                sum++;
            else
                break;

        cout << sum << endl;
    }
    return 0;
}
