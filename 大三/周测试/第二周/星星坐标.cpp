#include<bits/stdc++.h>

using namespace std;

int main() {
    int q;
    while(~scanf("%d",&q)) {
        while( q-- ) {
            int n;
            int x1 = 100000,y1 = 100000,x2 = -100000,y2 = -100000;
            int x,y,a,b,c,d;
            cin >> n;
            for (int i = 0; i < n; i++) {
                cin >> x >> y >> a >> b >> c >> d;
                a += y;  //ио
                b += x;  //ср
                c = y-c; //об
                d = x-d; //вС
                if( a < x1 )
                    x1 = a;
                if( b < y1 )
                    y1 = b;
                if( c < x2 )
                    x2 = c;
                if( d < y2 )
                    y2 = d;
            }
            if(x1 >= x2 && y1 >= y2)
                cout << '1' << endl;
            else
                cout << '0' << endl;
        }
    }

    return 0;
}
