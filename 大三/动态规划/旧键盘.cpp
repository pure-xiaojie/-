#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char a[100],b[100];

    int has[256] = {0};

    gets(a);
    gets(b);

    for(int i = 0; i < strlen(b); i++) {
        if(b[i] >= 'a' && b[i] <= 'z')
           b[i] = b[i] - 32;

        has[b[i]] = 1;
    }

    for(int i = 0; i < strlen(a); i++) {
        if(a[i] >= 'a' && a[i] <= 'z')
           a[i] = a[i] - 32;
        if(has[a[i]] == 0)
            cout << a[i];
        has[a[i]] = 1;
    }

    return 0;
}
