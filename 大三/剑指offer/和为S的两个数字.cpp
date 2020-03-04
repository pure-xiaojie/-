#include<bits/stdc++.h>

using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    int n = array.size();
    vector<int> res(2,0);
    vector<int> nu;
    int resmin = INT_MAX,flag = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(array[j] == sum - array[i]) {
                if(resmin > array[i]*array[j]) {
                    resmin = array[i]*array[j];
                    res[0] = array[i];
                    res[1] = array[j];
                    flag = 1;
                }
            }
        }
    }
    if(flag == 1)
        return res;
    else
        return nu;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int s,m,t;
        vector<int> array;
        cin >> t >> s;

        for(int i = 0; i < t; i++) {
            cin >> m;
            array.push_back(m);
        }
        vector<int> res = FindNumbersWithSum(array,s);

        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;

    }
    return 0;
}
