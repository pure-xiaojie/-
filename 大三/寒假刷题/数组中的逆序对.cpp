#include<bits/stdc++.h>

using namespace std;
int res;

void getRes(vector<int> data, int starts, int mid, int ends)
{
    vector<int> temp(ends-starts+1);
    int i = starts;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= ends) {
        if(data[i] <= data[j]) {
            temp[k++] = data[i++];
        }
        else {
            temp[k++] = data[j++];
            res = (res + mid - i + 1) % 1000000007;
        }
    }
    while(i <= mid) {
        temp[k++] = data[i++];
    }
    while(j <= ends) {
        temp[k++] = data[j++];
    }
    for(k = 0; k < temp.size(); k++)
        data[starts + k] = temp[k];
}
void twoSort(vector<int> data, int starts, int ends)
{
    if(starts >= ends)
        return;
    int mid = (starts + ends) / 2;
    twoSort(data,starts,mid);
    twoSort(data,mid+1,ends);

    getRes(data, starts, mid, ends);
}

int InversePairs(vector<int> data) {
    int n = data.size();
    res = 0;

    if(n != 0)
        twoSort(data,0,n-1);
    return res;
}

int main()
{
    int n,m,t;
    cin >> n;
    while(n--) {
        cin >> m;
        vector<int> data;
        for(int i = 0; i < m; i++) {
            cin >> t;
            data.push_back(t);
        }
        cout << InversePairs(data) << endl;
    }
    return 0;
}
