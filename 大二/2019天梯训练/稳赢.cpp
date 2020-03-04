#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;
char a[10000][10];

int main()
{
    int n;
    cin >> n;
    int i = 0;
    while(cin >> a[i])
    {
        if(!strcmp(a[i],"End"))
            break;
        i++;
    }
    int t = 0;
    for(int j = 0; j < i; j++)
    {
        if(t == n)
        {
            printf("%s\n",a[j]);
            t = 0;
            continue;
        }
        else if(!strcmp(a[j],"ChuiZi"))
            printf("Bu\n");
        else if(!strcmp(a[j],"JianDao"))
            printf("ChuiZi\n");
        else if(!strcmp(a[j],"Bu"))
            printf("JianDao\n");
        t++;
    }
    return 0;
}
