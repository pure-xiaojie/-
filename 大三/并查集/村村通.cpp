#include<cstdio>
#include<iostream>

using namespace std;
int city[1010];

int find_father(int n)  //查找祖先节点，当节点记录的祖先是自己，则表示查找到祖先了
{
    if(city[n] == n) {
        return n;
    }
    return find_father(city[n]);
}
void merge_ab(int a,int b)   //合并节点：设置共同祖先
{
    int x = find_father(a);
    int y = find_father(b);
    if(x != y)
        city[y] = x;
}
int main()
{
    int n,m,t;
    cin >> t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0; i <= n; i++)  //最开始的时候，每个节点自己属于一个圈子
            city[i] = i;

        int a,b;
        for(int i = 0; i < m; i++) {
            scanf("%d%d",&a,&b);
            merge_ab(a,b);
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {   //n个朋友构成的圈子数
            if(city[i] == i)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}
