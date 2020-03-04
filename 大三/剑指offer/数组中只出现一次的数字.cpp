#include<bits/stdc++.h>

using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        map<int,int> mp;
        int n = data.size();

        for (int i = 0; i < n; i++) {
            mp[data[i]]++;
        }
        int t = 0;
        for (int i = 0; i < n; i++) {
            if(mp[data[i]] == 1) {
                if(t == 0) {
                    *num1 = data[i];
                    t = 1;
                }
                else {
                    *num2 = data[i];
                    break;
                }
            }

        }
        cout << *num1 << *num2 << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i  < n; i++) {
        vector<int> data;
        int num1 = 0,num2 = 0;
        int m,t;
        cin >> m;
        for (int j = 0; j < m; j++){
            cin >> t;
            data.push_back(t);
        }
        FindNumsAppearOnce(data,&num1,&num2);
        cout << num1 << " " << num2 << endl;

    }

    return 0;
}
