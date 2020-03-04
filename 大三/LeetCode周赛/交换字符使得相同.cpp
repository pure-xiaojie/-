#include<bits/stdc++.h>

using namespace std;

int minimumSwap(string s1, string s2) {
    int n = 0, m = 0;

    for (int i = 0; i < s1.size(); i++) {
        if(s1[i] == 'x' && s2[i] == 'y')
            n++;
        if(s1[i] == 'y' && s2[i] == 'x')
            m++;
    }

    if(n%2 + m%2 == 1)
        return -1;

    int res = n/2 + m/2;

    if(n % 2 == 1)
        res += 2;

    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string a,b;
        cin >> a >> b;
        cout << minimumSwap(a,b) << endl;
    }
    return 0;
}
