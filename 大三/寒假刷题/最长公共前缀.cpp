#include<bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    string res = "";
    if(n == 0)
        return res;

    for(int i = 0,j; i < strs[0].size(); i++) {
        for(j = 1; j < n; j++) {
            if(strs[0][i] != strs[j][i])
                return res;
        }

        res += strs[0][i];
    }
    return res;
}

int main()
{
    int n,m;
    string str;

    cin >> n;
    while(n--)
    {
        vector<string > s;
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> str;
            s.push_back(str);
        }
        cout << longestCommonPrefix(s) << endl;

    }
    return 0;
}
