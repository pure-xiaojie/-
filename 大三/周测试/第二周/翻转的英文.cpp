#include<bits/stdc++.h>

using namespace std;
char str[100005];

int main() {

    gets(str);
    int len = strlen(str);
    for(int i = len - 1; i >= 0; i--) {
        if(str[i] == ' ') {
            for(int j = i + 1; j < len && str[j] != ' '; j++)
                cout << str[j];
            cout << ' ';
        } else if(i == 0) {
            for(int j = i; j < len && str[j] != ' '; j++)
                cout << str[j];
        }

    }

    return 0;
}
