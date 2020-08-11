#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int t,n,k = 1;

    int res[21] = {0,0,0,0,1,
                   1,2,3,3,4,
                   5,6,7,7,8,9,10,11,12,13,14};
    cin >> t;
    while(k <= t) {
        cin >> n;
        printf("Case #%d: %d\n",k++,res[n]);
    }
    return 0;
}
