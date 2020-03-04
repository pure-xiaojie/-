#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    int a,b,c,k=1;
    scanf("%d",&n);
    while(n--)
    {
        cin >> a >> b >> c;
        if(c - a < b)
            printf("Case #%d: true",k++);
        else
            printf("Case #%d: false",k++);
        if(n > 0)
            printf("\n");
    }
    return 0;
}
