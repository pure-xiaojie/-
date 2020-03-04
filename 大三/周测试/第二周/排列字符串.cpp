#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n)) {
        char ch[11],s[11];
        cin >> ch;
        int len = strlen(ch);

        if(n == 1) {
            for(int i = len-1; i >= 0; i--)
                cout << ch[i];
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                cin >> s;
                for(int j = 0; j < strlen(s); j++) {
                    ch[j] = ch[j] ^ s[j];
                }

            }
            cout << ch;
        }
        cout << endl;
    }

    return 0;
}

