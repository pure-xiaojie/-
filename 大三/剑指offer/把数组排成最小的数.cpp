#include<bits/stdc++.h>
#include<string>

using namespace std;

static bool cmp(int a, int b) {
    string A = "";
    string B = "";
    A += to_string(a);
    A += to_string(b);

    B += to_string(b);
    B += to_string(a);

    return A < B;
}
string PrintMinNumber(vector<int> numbers) {
    string res="";
    sort(numbers.begin(),numbers.end(),cmp);

    for(int i = 0; i < numbers.size(); i++) {
        res += to_string(numbers[i]);
    }
    return res;
}

int main()
{
    int n,m,t;
    cin >> n;
    while(n--) {
        vector<int> num;
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> t;
            num.push_back(t);
        }
        cout << PrintMinNumber(num) << endl;
    }
    return 0;
}
