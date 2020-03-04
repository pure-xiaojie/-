#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int a,b,x,y,n;
    int bar[100][4];
    cin >> a >> b;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> bar[i][0] >> bar[i][1] >> bar[i][2] >> bar[i][3];

    x = a,y=b;
    for(int i = 0; i < n; i++)
    {
        int k = bar[i][0] + bar[i][2];
        if( k== bar[i][1] && k != bar[i][3])
            a--;
        else if(k == bar[i][3] && k != bar[i][1])
            b--;

        if(a < 0)
        {
            cout << 'A' << endl;
            cout << y-b << endl;
            break;
        }
        if(b < 0)
        {
            cout << 'B' << endl;
            cout << x-a << endl;
            break;
        }

    }

    return 0;
}
