#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findContentChildren(int g[],int n, int s[],int m) {
    sort(g,g+n);
    sort(s,s+m);

    int count = 0;
    for(int i = 0,j = 0; i < n && j < m;) {
        if(g[i] <= s[j]) {
            i++;
            count++;
        }
        j++;

    }
    return count;
}

int main() {
    int a[]= {1,2};
    int b[]= {1,2,3};
    cout << findContentChildren(a,2,b,3) << endl;
    return 0;
}

