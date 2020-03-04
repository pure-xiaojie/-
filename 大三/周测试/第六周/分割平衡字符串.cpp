#include<bits/stdc++.h>

using namespace std;

int balancedStringSplit(string s) {
    int len = s.size();
    int a[1000];
    for (int i = 0; i < len;i++) {
        if(s[i] == 'R')
            a[i] = 1;
        else
            a[i] = -1;
    }
    int sum = 0,num = 0;
    for (int i = 0; i < len;i++) {
        sum += a[i];
        if(sum == 0) {
            num++;
            sum = 0;
        }
    }
    return num;
}

int main(){

    int n;
    string s;
    cin >> n;
    while(n--) {
        cin >> s;
        cout << balancedStringSplit(s) << endl;
    }
    return 0;
}
