#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
char a[10000][11];

int main()
{
    int i = 0;
    while(cin >> a[i])
    {
        if(strcmp(a[i],".") == 0)
            break;
        i++;
    }
    if(i < 2)
        printf("Momo... No one is for you ...");
    else if(i < 14)
        printf("%s is the only one for you...",a[1]);
    else
        printf("%s and %s are inviting you to dinner...",a[1],a[13]);
    return 0;
}
