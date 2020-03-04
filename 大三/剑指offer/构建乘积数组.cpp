#include<bits/stdc++.h>

using namespace std;

//B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
//从左到右算 B[i]=A[0]*A[1]*...*A[i-1]
//从右到左算B[i]*=A[i+1]*...*A[n-1]
vector<int> multiply(const vector<int>& A) {
    int n = A.size();
    vector<int> res(n);

    int s = 1;
    for(int i = 0; i < n; s *= A[i++]) {
        res[i] = s;
    }
    s = 1;
    for(int i = n-1; i >= 0; s *= A[i--]) {
        res[i] *= s;
    }
    return res;
}

int main()
{
    vector<int> s;
    s.push_back(1);
    s.push_back(2);
    s.push_back(3);
    s.push_back(4);
    s.push_back(5);

    vector<int> res = multiply(s);

    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}

