#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> str;
    map<string,set<string>> mp;

    int n;
    cin >> n;

    while(n--) {
        string a,b;
        cin >> a >> b;
        if(!mp.count(b))
            str.push_back(b);
        mp[b].insert(a);
    }

    for(auto s : str) {
        cout << s;

        for(auto t : mp[s])
            cout  << " " << t;

        cout << endl;
    }
    return 0;
}
