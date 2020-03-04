#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
    char num[15];
    int seatOne;
    int seatTwo;
}test[1005];

bool cmp(node a, node b)
{
    return a.seatOne < b.seatOne;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> test[i].num >> test[i].seatOne >> test[i].seatTwo;

    int m,a[1001];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> a[i];

    sort(test+1,test+n+1,cmp);

    for(int i = 1; i <= m; i++)
        cout << test[a[i]].num << " " << test[a[i]].seatTwo << endl;
    return 0;
}
