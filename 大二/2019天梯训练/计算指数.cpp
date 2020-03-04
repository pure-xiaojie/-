#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int a[11] = {1,2,4,8,16,32,64,128,256,512£¬1024};
    int n;
    cin >> n;
    printf("2^%d = %d",n,a[n]);
    return 0;
}
