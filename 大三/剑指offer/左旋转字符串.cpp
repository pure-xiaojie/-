#include<bits/stdc++.h>

using namespace std;

string LeftRotateString(string str, int n) {
    int len = str.size();
    if(len < n)
        return NULL;
    string res = &str[n];
    for(int i = 0; i < n; i++) {
        res.push_back(str[i]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        string str;
        int m;
        cin >> str >> m;
        cout << LeftRotateString(str,m) << endl;
    }
    return 0;
}
