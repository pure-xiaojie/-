#include<bits/stdc++.h>

using namespace std;

double Power(double base, int exponent) {
        if(base == 0)
            return 0;
        if(exponent == 0)
            return 1;
        int flag = 1;
        if(exponent < 0) {
            exponent *= -1;
            flag = 0;
        }
        double sum = 1;
        for(int i = 1; i <= exponent; i++) {
            sum *= base;
        }

        if(flag)
            return sum;
        else
            return 1.0/sum;

}

int main()
{
    int n,m;
    double base;
    cin >> n;
    while(n--) {
        cin >> base >> m;
        cout << Power(base,m) << endl;
    }
    return 0;
}
