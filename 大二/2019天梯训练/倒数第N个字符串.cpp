
#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    int l,n,i;
    cin >> l >> n;
    int m = pow(26,l) - n;
    char c[6];
    i = 0;
    while(l--)
    {
        c[i++] = 'a' + m % 26;
        m /= 26;
    }
    for(int j = i - 1; j >= 0; j--)
        cout << c[j];
    cout << endl;
    return 0;
}
