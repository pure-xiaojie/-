#include<bits/stdc++.h>

using namespace std;

bool IsContinuous( vector<int> numbers ) {
    int n = numbers.size();
    int min_n = 14, max_n = -1;
    int coun[14] = {0};

    if(n < 5)
        return false;
    for(int i = 0; i < n; i++) {
        if(numbers[i] == 0)
            continue;
        coun[numbers[i]]++;
        if(coun[numbers[i]] >= 2)
            return false;
        if(max_n < numbers[i])
            max_n = numbers[i];
        if(min_n > numbers[i])
            min_n = numbers[i];

    }
    if(max_n - min_n < 5)
        return true;
    return false;
}

int main()
{
    int n,m,t;
    cin >> n;
    while(n--)
    {
        vector<int> numbers;
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> t;
            numbers.push_back(t);
        }
        cout << IsContinuous(numbers) << endl;
    }
    return 0;
}
