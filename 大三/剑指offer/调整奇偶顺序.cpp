#include<bits/stdc++.h>

using namespace std;

void reOrderArray(vector<int> &array) {
    vector<int> s;
    for (int i = 0; i < array.size(); i++) {
        if(array[i] % 2 != 0)
            s.push_back(array[i]);
    }
    for (int i = 0; i < array.size(); i++) {
        if(array[i] % 2 == 0)
            s.push_back(array[i]);
    }
    array = s;
}

int main()
{
    int n,m,t;
    cin >> n;
    while (n--) {
        vector<int> array;
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> t;
            array.push_back(t);
        }
        reOrderArray(array);
        for(int i = 0; i < m; i++)
            cout << array[i] << " ";
        cout << endl;
    }
    return 0;
}
