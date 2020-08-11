#include<bits/stdc++.h>

using namespace std;

struct node {
    int cnt;
    int time;
}pe[100005];

bool compare(node a, node b) {
    return a.time < b.time;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> pe[i].cnt >> pe[i].time;
    }

    sort(pe,pe+t,compare);

    int res = 0;
    int left = 0, right = t-1;

    while(left <= right) {
        int number = min(pe[left].cnt,pe[right].cnt);

        number /= (left == right) ? 2 : 1;   //若left == right,number折半

        res = max(res,pe[left].time+pe[right].time);

        pe[left].cnt -= number;
        pe[right].cnt -= number;

        left += (pe[left].cnt == 0) ? 1 : 0;
        right += (pe[right].cnt == 0) ? -1 : 0;
    }
    cout << res << endl;
    return 0;
}
