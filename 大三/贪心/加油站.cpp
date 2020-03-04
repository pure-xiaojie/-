#include<bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int  rest = 0,run = 0,start = 0;
    for(int i = 0; i < gas.size(); i++) {
        run += (gas[i] - cost[i]);
        rest += (gas[i] - cost[i]);
        if(run < 0) {
            start = i + 1;
            run = 0;
        }
    }
    return rest < 0 ? -1 : start;
}

int main()
{
    int n;
    while(~scanf("%d",&n)) {
        int m;
        vector<int> gas;
        vector<int> cost;
        for(int i = 0; i < n; i++) {
            cin >> m;
            gas.push_back(m);
        }
        for(int i = 0; i < n; i++) {
            cin >> m;
            cost.push_back(m);
        }
        cout << canCompleteCircuit(gas,cost) << endl;
    }
    return 0;
}
