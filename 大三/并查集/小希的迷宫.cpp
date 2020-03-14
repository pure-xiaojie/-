#include<cstdio>
#include<iostream>

using namespace std;
const int maxn = 100010;
int city[maxn];
int flag[maxn];

int find_father(int n)
{
    if(n == city[n])
        return n;
    return find_father(city[n]);
}
bool merge_nm(int n, int m)
{
    int x = find_father(n);
    int y = find_father(m);
    if(x == y)
        return false;
    city[x] = y;
    return true;

}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n == -1 && m == -1)
            break;
        for(int i = 0; i <= 100000; i++) {
            city[i] = i;
            flag[i] = 0;
        }
        bool is = merge_nm(n,m);
        flag[n] = 1;
        flag[m] = 1;
        if(m == 0 && n == 0)       //若一组数据的开头即是0,0；输出Yes
            printf("Yes\n");

        while(scanf("%d%d",&n,&m),n&&m)
        {
            if(merge_nm(n,m) == false)   //何必，若返回false，表示有相同的父节点
                is = false;     //记录一下状态
            flag[n] = 1;
            flag[m] = 1;
        }

        if(is == false)
            printf("No\n");
        else {
            int res = 0;
            for(int i = 0; i <= 100000; i++) {   //统计存在几个集合
                if(flag[i] && city[i] == i)
                    res++;
            }
            if(res == 1)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}

