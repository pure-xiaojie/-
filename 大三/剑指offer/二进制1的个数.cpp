#include<bits/stdc++.h>

using namespace std;

//����һ
int method1(int m) {
    int s = 0;
    while (m != 0) {
        m = (m-1) & m;
        s++;
    }
    return s;
}

//������
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
