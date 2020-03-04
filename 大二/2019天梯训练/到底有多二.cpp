#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char n[51];
    cin >> n;

    int sum = 0,t,len = strlen(n);
    t = len;
    for(int i = 0; i < len; i++)
        if(n[i] == '2')
            sum++;
    if(n[0] == '-')
        len--;

    float f = 1.0*sum/len;
    if((n[t-1]-48)%2 == 0)
    {
        f *= 2;
    }
    if(n[0] == '-')
        f *= 1.5;

    printf("%.2f%%\n",f*100);
    return 0;
}
