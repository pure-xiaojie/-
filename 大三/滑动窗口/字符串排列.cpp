#include<bits/stdc++.h>

using namespace std;

bool minWindow(string s, string t) {
    unordered_map<char,int> window,need;

    for(char c : s) {
        need[c]++;
    }

    int left = 0,right = 0;
    int valid = 0;

    while(right < t.size()) {
        char c = t[right];
        right++;

        if(need.count(c)) {
            window[c]++;
            if(need[c] == window[c])
                valid++;
        }

        while(valid == need.size()) {
            if(need.size() == right-left)
                return true;

            char d = t[left];
            left++;

            if(need.count(d)) {
                if(need[d] == window[d])
                    valid--;
                window[d]--;
            }
        }

    }
    return false;
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
