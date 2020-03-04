#include<bits/stdc++.h>

using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    int n = pushV.size();

    stack<int> s;
    int j = 0;
    for(int i = 0; i < n; i++) {
        s.push(pushV[i]);

        while(!s.empty() && (s.top() == popV[j])) {
            s.pop();
            j++;
        }
    }

    if(s.empty())
        return true;
    else
        return false;
}

int main()
{
    int n,m,t;
    cin >> n;
    while (n--) {
        vector<int> a,b;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> t;
            a.push_back(t);
        }
        for (int i = 0; i < m; i++) {
            cin >> t;
            b.push_back(t);
        }
        cout << IsPopOrder(a,b) << endl;
    }
    return 0;
}
