#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void build(int n,char s1[],char s2[],char s[])
{
    if(n<=0)
        return;
    int p=strchr(s2,s1[0])-s2;  //查找字符串s2中首次出现字符s1的位置，

    build(p,s1+1,s2,s);
    build(n-p-1,s1+p+1,s2+p+1,s+p);
    s[n-1]=s1[0];
}
int main()
{
    char s1[30],s2[30],s[30];   //前、中、后序
    cin >> s1 >> s2;

    int n=strlen(s1);
    build(n,s1,s2,s);
    s[n]='\0';
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s << endl;

    return 0;
}
