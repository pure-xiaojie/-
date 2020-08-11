#include<bits/stdc++.h>

using namespace std;

int word(string s) {
    unordered_map<char,int> window;

    int left = 0,right = 0;
    int res = 0;

    while(right < s.size()) {
        char c = s[right];
        right++;

        window[c]++;

        while(window[c] > 1) {
            char d = s[left];

            left++;

            window[d]--;
        }

        res = max(res,right-left);
    }

    return res;
}

int mian()
{
    int n;
    string s;

    cin >> n;
    while(n--) {
        cin >> s;
        cout << word(s) << endl;
    }
    return 0;
}
