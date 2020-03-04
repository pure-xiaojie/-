#include<cstdio> 
#include<cstring> 
#include<cmath> 
#include<iostream>

using namespace std;
int num[1000000];

int main()
{
    int a,n;
    cin >> a >>n;
    if(n == 0)
        printf("0\n");
    else
    {
        int flag = 0,j = 0;
        for(int i = n; i >= 1; i--,j++)
        {
            int t = a*i+flag;
            flag = t / 10;
            num[j] = t%10;
        }
        if(flag > 0)
        {
            num[j] = flag;
            j++;
        }
        for(int i = j-1; i >=0; i--)
            cout << num[i];
    }
}
