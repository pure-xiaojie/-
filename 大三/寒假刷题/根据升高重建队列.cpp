#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if(a[0] > b[0])
        return true;
    if(a[0] == b[0] && a[1] < b[1])
        return true;
    return false;
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(),cmp);
    vector<vector<int> > res;

    for(int i = 0; i < people.size(); i++) {
        res.insert(res.begin() + people[i][1],people[i]);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        vector<vector<int> > people;
        int m,a,b;
        cin >> m;
        while(m--) {
            vector<int> per;
            cin >> a >> b;
            per.push_back(a);
            per.push_back(b);
            people.push_back(per);
        }
        vector<vector<int> > res = reconstructQueue(people);
        for(int i = 0; i < res.size(); i++) {
            cout << '[' << res[i][0] << ',' << res[i][1] << "]  ";
        }
        cout << endl;
    }
    return 0;
}
