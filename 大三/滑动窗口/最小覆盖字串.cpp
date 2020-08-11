#include<bits/stdc++.h>

using namespace std;

string minWindow(string s, string t) {
    unordered_map<char,int> window,need;

    for(char c : t) {
        need[c]++;
    }

    int left = 0, right = 0;
    int valid = 0;
    int start = 0,len = INT_MAX;

    while(right < s.size()) {
        char c = s[right];
        right++;

        if(need.count(c)) {
            window[c]++;
            if(window[c] == need[c])
                valid++;
        }

        while(valid == need.size()) {
            if(right-left < len) {
                start = left;
                len = right-left;
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
    return len == INT_MAX ? "" : s.substr(start,len);

}

int main()
{
    int n;
    string s,t;

    cin >> n;
    while(n--) {
        cin >> s >> t;
        cout << minWindow(s,t) << endl;
    }
    return 0;
}
