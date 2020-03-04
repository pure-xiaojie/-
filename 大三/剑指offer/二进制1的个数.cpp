#include<bits/stdc++.h>

using namespace std;

//方法一
int method1(int m) {
    int s = 0;
    while (m != 0) {
        m = (m-1) & m;
        s++;
    }
    return s;
}

//方法二
int method2(int m) {
    int s = 0;
    long n = 1;
    while (n != 0) {
        if((m & n) != 0)
            s++;
        n <<= 1;
    }
    return s;
}

int main()
{
    int n,m;
    cin >> n;
    while (n--) {
        cin >> m;
        cout << method2(m) << endl;
    }
    return 0;
}
