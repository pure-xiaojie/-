#include<bits/stdc++.h>

using namespace std;

int t1(int m,int n)
{
    if(n == 1 || m == 0)
        return 1;
    if(m < n)
        return t1(m,m);
    else
        return t1(m,n-1) + t1(m-n,n);
}


int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> m >> n;
        cout << t1(m,n) << endl;
    }
    return 0;
}
