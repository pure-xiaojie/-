#include<bits/stdc++.h>

using namespace std;
int dep[100005];  //结点深度，默认为0

int main()
{
    int n;
    cin >> n;
    int a,b;
    for(int i = 1; i < n; i++) {
        cin >> a >> b;
        dep[b] = dep[a] + 1;    //当前结点b的深度为前一个结点的深度+1
    }
    int maxDeepth = 0;   //存放最大深度
    for(int i = 1; i <= n; i++) {
        maxDeepth = maxDeepth < dep[i] ? dep[i] : maxDeepth;
    }

    //n-maxDeepth-1为其它结点，需遍历两遍，所以*2     maxDeepth最大深度，最后遍历
    cout << 2 * (n-maxDeepth-1) + maxDeepth << endl;
    return 0;
}
