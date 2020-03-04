#include<bits/stdc++.h>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.size();
    set<string> m(wordDict.begin(),wordDict.end());
    vector<bool> flag(len+1, false);

    flag[0] = true;
    for(int i = 1; i <= s.size(); ++i) {
        for(int j = 0; j < i; j++) {
            if(flag[j] && m.find(s.substr(j,i-j)) != m.end()) {
                flag[i] = true;
                break;
            }
        }
    }
    return flag[len];
}

int main()
{
    int n,m;
    cin >> n;
    while(n--) {
        string str,t;
        vector<string> word;
        cin >> str >> m;
        for(int i = 0; i < m; i++) {
            cin >> t;
            word.push_back(t);
        }
        cout << wordBreak(str,word) << endl;
    }
    return 0;
}
