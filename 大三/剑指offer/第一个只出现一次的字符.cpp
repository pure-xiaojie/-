#include<bits/stdc++.h>

using namespace std;

int FirstNotRepeatingChar(string str) {
    int n = str.size();
    map<char,int> m;

    for(int i = 0; i < n; i++) {
        m[str[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if(m[str[i]] == 1)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        cout << FirstNotRepeatingChar(s) << endl;
    }
    return 0;
}
