#include<bits/stdc++.h>

using namespace std;

int wordWindow(string s, string t) {
    unordered_map<char,int> window,need;
    vector<int> res;

    for(char c : t) {
        need[c]++;
    }

    int left = 0, right = 0;
    int valid = 0;

    while(right < s.size()) {
        char c = s[right];
        right++;

        if(need.count(c)) {
            window[c]++;
            if(need[c] == window[c])
                valid++;
        }

        while(right-left >= t.size()) {
            if(need.size() == valid) {
                res.push_back(left);
            }

            char d = s[left];
            left++;

            if(need.count(d)) {
                if(window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }

    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << ',';
    }

    return res.size();

}

int main()
{
    int n;
    string s,t;

    cin >> n;
    while(n--) {
        cin >> s >> t;
        cout << wordWindow(s,t) << endl;
    }
    return 0;
}
