#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 100001;
int fri[maxn];
int sum[maxn];
int res;

int find_fri(int n)
{
    if(fri[n] == n)
        return n;
    return fri[n] = find_fri(fri[n]);    //return find_fri(fri[n]);会出现超时，因此需要状态跟着改变
}
void merge_ab(int a,int b)
{
    int x = find_fri(a);
    int y = find_fri(b);
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
        for(int i = 0; i <= maxn; i++) {
            fri[i] = i;
            sum[i] = 1;
        }
        int a,b;
        res = 1;
        for(int i = 0; i < n; i++) {
            scanf("%d%d",&a,&b);
            merge_ab(a,b);
        }
        printf("%d\n",res);
    }
    return 0;
}
