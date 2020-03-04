#include<bits/stdc++.h>

using namespace std;

int subtractProductAndSum(int n) {
    int sum1 = 1,sum2 = 0;
    while(n != 0) {
        sum1 *= n % 10;
        sum2 += n % 10;
        n/=10;
    }
    return sum1-sum2;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        cout << subtractProductAndSum(m) << endl;
    }
    return 0;
}
