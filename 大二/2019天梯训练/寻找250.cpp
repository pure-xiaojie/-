#include<cstdio>
#include<iostream>

using namespace std;
int num[100000];

int main()
{
    int t = 1;
    while(scanf("%d",&num[t]) != EOF)
    {
         if(num[t] == 250)
            break;
         t++;
    }
    cout << t;
    return 0;
}
