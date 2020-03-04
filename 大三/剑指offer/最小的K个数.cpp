#include<bits/stdc++.h>

using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    int n = input.size();
    if(n < k) {
       vector<int> s;
       return s;
    }

    sort(input.begin(),input.end(),less<int>());
    vector<int> res(k,INT_MAX);

    for (int i = 0; i < input.size(); i++) {
        for(int j = 0; j < k; j++) {
            if(input[i] < res[j]) {
                res[j] = input[i];
                break;
            }
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        int m,t,k;
        vector<int> input;
        vector<int> output;
        cin >> m >> k;
        for (int i = 0; i < m; i++) {
            cin >> t;
            input.push_back(t);
        }

        output = GetLeastNumbers_Solution(input,k);
        for(int i = 0; i < output.size(); i++) {
            cout << output[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
