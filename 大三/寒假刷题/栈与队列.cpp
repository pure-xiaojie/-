#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--) {
        int m, t;
        char str[5], ch[5];
        scanf("%d %s",&m, str);
        if(!strcmp(str, "FIFO")) {
            queue<int> q;
            for(int i = 0; i < m; i++) {
                scanf("%s",ch);
                if(!strcmp(ch, "IN")) {
                    cin >> t;
                    q.push(t);
                } else {
                    if(!q.empty()) {
                        cout << q.front() << endl;
                        q.pop();
                    } else {
                        cout << "None" << endl;
                    }

                }
            }
        } else if(!strcmp(str, "FILO")) {
            stack<int> s;
            for(int i = 0; i < m; i++) {
                scanf("%s",ch);
                if(!strcmp(ch, "IN")) {
                    cin >> t;
                    s.push(t);
                } else {
                    if(!s.empty()) {
                        cout << s.top() << endl;
                        s.pop();
                    } else {
                        cout << "None" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
