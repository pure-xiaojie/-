#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    int n,a,b;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(abs(b-(a-100)*0.9*2) < (a-100)*0.9*2*0.1)
            printf("You are wan mei!\n");
        else if((a-100)*0.9*2 > b)
            printf("You are tai shou le!\n");
        else
            printf("You are tai pang le!\n");
    }
    return 0;
}
