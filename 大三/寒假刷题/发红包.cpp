#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        int res = a;
        while(a >= b)
        {
            res += a/b;
            a = a-a/b*(b-1);
        }
        cout << res << endl;
    }
    return 0;
}
