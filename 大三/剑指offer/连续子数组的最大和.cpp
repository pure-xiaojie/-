#include<bits/stdc++.h>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
    int n = array.size();

    int sum,max,res = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum = array[i];
        max = array[i];

        for(int j = i+1; j < n; j++) {
            sum += array[j];
            if(sum > max)
                max = sum;
        }

        if(res < max)
            res = max;
    }
    return res;

}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        int m,t;
        vector<int> input;

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> t;
            input.push_back(t);
        }
        cout << FindGreatestSumOfSubArray(input) << endl;
    }
    return 0;
}

