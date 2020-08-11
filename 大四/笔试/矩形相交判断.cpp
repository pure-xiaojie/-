#include<bits/stdc++.h>

using namespace std;

int main()
{
    //矩形1
    int x1,y1,x2,y2;
    //矩形2
    int a1,b1,a2,b2;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> a1 >> b1 >> a2 >> b2;

    if(b1 > y2 && b2 > y2)
        cout << 0;
    else if(b1 < y1 && b2 < y1)
        cout << 0;
    else if(a1 > x2 && a2 > x2)
        cout << 0;
    else if(a1 < x1 && a2 < x1)
        cout << 0;
    else
        cout << 1;
    return 0;
}
