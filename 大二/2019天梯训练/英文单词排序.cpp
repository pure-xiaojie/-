#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

struct stu
{
    char a[11];
    int n;
} s[21];

int cmp(stu a,stu b)
{
    return a.n < b.n;

}

int main()
{
    char str[11];
    gets(str);
    int i = 0;
    while(strcmp(str,"#") != 0)
    {
        strcpy(s[i].a,str);
        s[i].n = strlen(str);
        i++;
        gets(str);
    }
    sort(s,s+i,cmp);
    for(int j = 0; j < i; j++)
        printf("%s ",s[j].a);
    return 0;
}

