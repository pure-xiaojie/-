#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

int dfs(char *pre, char *mid, int n)
{
    if(n == 0)
        return 0;
    int i;
    for(i = 0; i< n; i++)
    {
        if(mid[i] == pre[0])
            break;
    }

    int left = dfs(pre+1,mid,i);
    int right = dfs(pre+i+1,mid+i+1,n-i-1);
    return max(left,right)+1;

}

int main()
{
    int n;
    cin >> n;
    char pre[n+1],mid[n+1];
    cin >> pre >> mid;
    cout << dfs(pre,mid,n);
    return 0;
}

