#include<bits/stdc++.h>

using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if(n <= 0 || m < 0)
        return -1;
    if(n == 1)
        return 0;
    return (LastRemaining_Solution(n-1,m)+m)%n;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int s,m;
        cin >> s >> m;
        cout << LastRemaining_Solution(s,m) << endl;
    }
    return 0;
}
