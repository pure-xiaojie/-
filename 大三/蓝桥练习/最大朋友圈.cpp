#include<cstdio>
#include<iostream>
#define maxn 1000005
int fri[maxn];
int sum[maxn];
int res;

using namespace std;

int find_F(int x)
{
    if(x == fri[x])
        return x;
    return fri[x] = find_F(fri[x]);
}
void merge_ab(int a,int b) {
    int x = find_F(a);
    int y = find_F(b);

    if(x != y) {
        fri[x] = y;
        sum[y] += sum[x];
        res = max(res,sum[y]);
    }

}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < maxn; i++) {
            fri[i] = i;
            sum[i] = 1;
        }
        int a,b;
        res = 1;
        for(int i = 0; i < n; i++) {
           cin >> a >> b;
           merge_ab(a,b);
        }
        cout << res << endl;
    }
    return 0;
}
