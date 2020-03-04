#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>

using namespace std;

int main()
{
    char a[1005];
    int n;

    scanf("%s %d",a,&n);
    int len = strlen(a);

    int t = 0,s = 0;
    for(int i = 0; i < len; i++)
    {
        s = s* 10 + a[i]-'0';
        while(s < n && t == 0)
        {
            s = s* 10 + a[++i]-'0';
        }
        printf("%d",s/n);
        s = s % n;
        t = 1;
    }
    printf(" %d",s);
    return 0;
}
