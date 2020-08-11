#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
char a[10000],b[10000];

int main()
{

    while(~scanf("%s %s",a,b)) {
        if(strcmp(a,b) == 0)
            cout << a << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}
