#include<bits/stdc++.h>

using namespace std;

int Sum_Solution(int n) {
    return n*(1+n)/2;
}

int main()
{
    int n;
    cin >> n;
    cout << Sum_Solution(n) << endl;
    return 0;
}
