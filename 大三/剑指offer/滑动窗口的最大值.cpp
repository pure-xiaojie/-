#include<bits/stdc++.h>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> res;
    int len = num.size();
    if(len < size)
        return res;

    for(int i = 0; i < len-size+1; i++) {
        int maxn = num[i];
        for(int j = i; j < i+size; j++) {
            if(maxn < num[j])
                maxn = num[j];
        }
        res.push_back(maxn);
    }
    return res;
}

int main()
{
    vector<int> num;
    int size,m;

    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> m;
        num.push_back(m);
    }

    int t;
    cin >> t;

    vector<int> res = maxInWindows(num,t);

    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
