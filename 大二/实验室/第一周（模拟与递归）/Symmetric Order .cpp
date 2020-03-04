#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n,t = 0;
    while(cin >> n,n)
    {
        char a[16][26];
        for(int i = 0; i < n; i++)
            scanf("%s",a[i]);

        cout << "SET " << ++t << endl;
        for(int i = 0; i < n; i+=2)
            cout << a[i] << endl;

        for(int i =(n%2==0?n-1:n-2); i > 0; i-=2)
            cout << a[i] << endl;

    }
    return 0;
}
