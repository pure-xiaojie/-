#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    string s[55];
    int vis[55] = {0};

    for (int i = 0; i < n; i++)
        cin >> s[i];

    map<string,int> mp;
    map<string,int>:: iterator iter;
    for(int i = 0; i < n; i++) {
        iter = mp.find(s[i]);
        if( iter != mp.end() ) {
            vis[iter->second] = 1;
            //iter->second = i;
            //cout << iter->first << "   " << iter->second << endl;
        }
        mp[s[i]] = i;
    }
    cout << mp.size() << endl;
    for(int i = 0; i < n; i++) {
        if(vis[i] == 0) {
            cout << s[i] << ' ';
        }
    }
    return 0;
}
