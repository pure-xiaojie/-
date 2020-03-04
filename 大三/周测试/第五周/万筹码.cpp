#include<bits/stdc++.h>

using namespace std;

int minCostToMoveChips(vector<int>& chips) {
    int len = chips.size();
    if(len == 1)
        return 0;
    int num1 = 0,num2 = 0;
    for(int i = 0; i < len; i++) {
        if(chips[i] % 2 == 0)
            num1++;
        else
            num2++;
    }
    if(num1 > num2)
        return num2;
    else
        return num1;
}

int main()
{
    int n,t,m;
    cin >> n;
    while(n--) {
        vector<int> s;
        cin >> t;
        for(int i = 0; i < t; i++) {
            cin >> m;
            s.push_back(m);
        }
        cout << minCostToMoveChips(s) << endl;
    }
    return 0;
}
