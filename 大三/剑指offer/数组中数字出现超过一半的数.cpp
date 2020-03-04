#include<bits/stdc++.h>

using namespace std;

int MoreThanHalfNum_Solution2(vector<int> numbers) {
    int n = numbers.size();

    int soldier = numbers[0];
    int coun = 1;

    for(int i = 1; i < n; i++) {
        if(numbers[i] == soldier)
            coun++;
        else
            coun--;

        if(coun == 0) {
            soldier = numbers[i];
            coun = 1;
        }

    }

    int num = 0;
    for(int i = 0; i < n; i++)
    {
        if(numbers[i] == soldier)
           num++;
    }
    if(num > n/2)
        return soldier;
    else
        return 0;
}

int MoreThanHalfNum_Solution(vector<int> numbers) {
    int n = numbers.size();
    sort(numbers.begin(),numbers.end());

    int num = numbers[n/2],coun = 0;

    for (int i = 0; i < n; i++) {
        if(num == numbers[i])
            coun++;
    }
    if(coun > n/2)
        return num;
    else
        return 0;
}

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int m,t;
        vector<int> numbers;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> t;
            numbers.push_back(t);
        }
        cout << MoreThanHalfNum_Solution2(numbers) << endl;
    }
    return 0;
}
