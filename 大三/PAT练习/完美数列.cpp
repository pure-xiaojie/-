#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long num[100005];

int main() {
    int n;
    long long p;
    cin >> n >> p;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    sort(num,num+n);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + sum; j < n; ++j) {
            if (num[j] > num[i] * p)
                break;
            sum++;
        }
    }
    cout << sum1;
    return 0;
}
