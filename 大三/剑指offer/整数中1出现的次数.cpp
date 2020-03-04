#include<bits/stdc++.h>

using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
    if(n == 0)
        return 0;
    int res = 1,s;
    for(int i = 10; i <= n; i++) {
        s = i;
        while(s){
            if(s % 10 == 1)
                res++;
            s /= 10;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        cout << NumberOf1Between1AndN_Solution(m) << endl;
    }
    return 0;
}


