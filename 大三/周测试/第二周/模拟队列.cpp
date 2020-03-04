#include<bits/stdc++.h>

using namespace std;

int main()
{
    queue<int> q;
    int n,v,m;
    char ch[10];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        if(strcmp(ch,"push") == 0) {
            cin >> m;
            q.push(m);
        }
        else if(strcmp(ch,"pop") == 0) {
            cout << q.front() << endl;
            q.pop();
        }
    }
    return 0;
}
