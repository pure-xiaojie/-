#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define max1 10010
#define max2 1000005

char s[max1],t[max2];
int next1[max1],cnt;


void kmp()
{
    int i,j=0 , m=strlen(s);
    for(i=0; t[i] != '\0'; i++)
    {
        while(j && s[j] != t[i])
            j=next1[j];
        if(s[j] == t[i])
            j++;
        if(j == m)
            cnt++;
    }
}

void find_next()
{
    next1[0] = 0;
    next1[1] = 0;
    int i,j;
    for(i=1; s[i] != '\0'; i++)
    {
        j = next1[i];
        while(j && s[j] != s[i])
            j = next1[j];
        next1[i+1] = (s[j] == s[i]) ? j + 1: 0;
    }
}

int main()
{
    int n ;
    cin >> n;
    while(n --)
    {
        cin >> s;
        find_next();
        cnt = 0;
        cin >> t;
        kmp();
        cout << cnt << endl;
    }
    return 0;
}
