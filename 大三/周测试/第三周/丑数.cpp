#include<bits/stdc++.h>

using namespace std;

int _gcb(int a,int b)//ตÝน้
{
    return a%b==0? b:_gcb(b,a%b);
}

int nthUglyNumber(int n, int a, int b, int c) {
     int s = n,t = n/a + n/b + n/c - _gcb(_gcb(a,b),c);
     while( s ) {
        if(s % a == 0 || s % b == 0 || s % c == 0)
            t++;
        if(t == n)
            break;
        s++;
     }
     return s;
}

int main()
{
    int n,a,b,c;
    while(~scanf("%d%d%d%d",&n,&a,&b,&c)) {
        cout << nthUglyNumber(n,a,b,c) << endl;
    }
    return 0;
}
