#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
double a[10001],b[10001],c[10001];

int main()
{
    int n;
    while(cin >> n,n)
    {
        int count=0;
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i] >> b[i];
            if(b[i] >= 0)
                c[count++]=4.5*3600/a[i]+b[i];
        }
        sort(c,c+count);
        cout << (int)ceil(c[0]) << endl;
    }
    return 0;
}

