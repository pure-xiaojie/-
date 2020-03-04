#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,a[150005],is[150005];

int main()
{
    while(~scanf("%lld",&n)) {
        memset(is,0,sizeof(is));          //初始化状态，因为是多个测试用例
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a,a+n);

        ll sum = 0;   //最有解
        for(int i = 0; i < n; i++) {
            if(is[a[i]-1] == 0 && a[i] != 1) {     //先判断该数的左边
                sum++;
                is[a[i-1]] = 1;
            }
            else if(is[a[i]] == 0 ) {       //左边不满足，判断该数位置
                sum++;
                is[a[i]] = 1;
            }
            else if(is[a[i]+1] == 0) {    //该数本身位置不满足，判断右边
                sum++;
                is[a[i]+1] = 1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
