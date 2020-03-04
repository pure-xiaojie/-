#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    vector<int> left(n);
    stack<int> sta;
    for (int i = 0; i < n; ++i)
    {
        left[i] = sta.size();
        while (!sta.empty() && sta.top() <= vec[i])
        {
            sta.pop();
        }
        sta.push(vec[i]);
    }

    while (!sta.empty())
    {
        sta.pop();
    }

    vector<int> right(n);
    for (int i = n - 1; 0 <= i; --i)
    {
        right[i] = sta.size();
        while (!sta.empty() && sta.top() <= vec[i])
        {
            sta.pop();
        }
        sta.push(vec[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << left[i] + 1 + right[i] << " ";
    }
    return 0;
}
