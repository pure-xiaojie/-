#include<bits/stdc++.h>

using namespace std;

struct node {
    int x;
    int hp;
}a[100005];

bool cmp(node a, node b) {
    return a.x < b.x;
}

int main()
{
    int n,y;
    cin >> n >> y;

    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].hp;
    }

    sort(a,a+n,cmp);

    int res = 0, left = 0;
    while(left < n) {
        int kill = a[left].hp;
        res += kill;

        int j = left+1;
        while(a[j].x <= 2*y + a[left].x) {
            a[j].hp -= kill;
            j++;
        }

        int k = left+1;
        while(a[k].hp <= 0) {
            k++;
        }

        left = k;
    }

    cout << res << endl;
    return 0;
}
