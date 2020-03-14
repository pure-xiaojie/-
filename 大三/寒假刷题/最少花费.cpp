#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n,v;
    while(~scanf("%d%d",&n,&v))
    {
        if(v >= n-1)
            cout << n-1 << endl;
        else {
            int t = v,res = v;
            for(int i = 1; i <= n-1; i++) {
                t--;
                if(i+t <= n-1) {
                    res += i;
                    t++;
                }
            }
            cout << res-1 << endl;
        }
    }
    return 0;
}
