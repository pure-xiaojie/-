#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    int lens = s.size();
    int lenp = p.size();
    vector<int> str_s(26,0),str_p(26,0);
    vector<int> res;

    int l = 0,r = 0;
    for(int i = 0; i < lenp; i++) {
        str_p[p[i]-'a']++;
        str_s[s[r++]-'a']++;
    }

    if(str_p == str_s)
        res.push_back(l);

    while(r < lens) {
        str_s[s[l++]-'a']--;
        str_s[s[r++]-'a']++;
        if(str_p == str_s)
            res.push_back(l);
    }
    return res;

}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        string s,p;
        vector<int> res;
        cin >> s >> p;
        res = findAnagrams(s,p);

        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
