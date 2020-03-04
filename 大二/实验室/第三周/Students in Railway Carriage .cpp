#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

char c[200005];

int main()
{
    int n,a,b;
    while(cin >> n >> a >> b)
    {
        int sum=a+b;

        cin >> c;

        int t;
        int pos;
        if(a>=b)
            pos=1;
        else
            pos=0;
        for(int i=0; c[i]; i++)
        {
            if(c[i]=='.')
            {
                if(a>0&&pos==1)
                    a--;
                else if(b>0&&pos==0)
                    b--;
                pos=!pos;
            }
            else
            {
                if(a>=b)
                    pos=1;
                else
                    pos=0;
            }
        }

        cout << sum-a-b << endl;
    }

    return 0;
}
