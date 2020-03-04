#include<cstdio>
#include<iostream>

using namespace std;

int judge(int a, int b)
{
   if(a%b == 0)
    return b;
   else
    judge(b, a%b);
}
int main()
{
    int t,a,b,c;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        c = 2*b;
        while(judge(a,c) != b)
            c += b;

        cout << c << endl;

    }
return 0;
}
