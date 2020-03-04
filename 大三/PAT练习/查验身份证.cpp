#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,s = 1;
    char id[100][18];
    int k[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char t[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

    cin >> n;
    for (int i = 0; i < n; i++) {
        int z = 0;
        cin >> id[i];
        for(int j = 0; j < 17; j++)
            z += (id[i][j] - '0') * k[j];

        if(id[i][17] != t[z%11]) {
            cout << id[i];
            if(i < n-1)
                cout << endl;
            s = 0;
        }
    }
    if(s == 1)
        cout << "All passed";
    return 0;
}
