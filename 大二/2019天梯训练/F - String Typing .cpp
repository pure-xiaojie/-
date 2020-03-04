#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    string s;
    int n;
    cin >> n >> s;

    int len = 0;
    for(int i = 0; i < n; i++)
    {
        int t = i + 1;
        int flag = 1;
        string sub = s.substr(0,t);
        //cout << sub << endl;
        for(int j = 0; j < t; j++)
        {
            if(t + i >= n || sub[j] != s[t+j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
            len = len>t?len:t;
    }
    if(len)
        cout << s.length() - len << endl;
    else
        cout << s.length() << endl;
    return 0;
}
