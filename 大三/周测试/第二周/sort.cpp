#include<bits/stdc++.h>

using namespace std;
const int maxn = 100005;

struct node
{
    char name[20];

}lis[maxn];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%s",lis[i].name);
    }

    for(int i = n-1; i >= 0; i--) {
        cout << lis[i].name;
        if(i != 0)
            cout << " ";
    }
    return 0;
}
