#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int a,b;
    scanf("%02d:%02d",&a,&b);
    if(a <= 12)
        printf("Only %02d:%02d.  Too early to Dang.",a,b);
    else
        for(int i = 0; i < a - 12; i++)
            printf("Dang");

    if(b > 0 && a >= 12)
        printf("Dang");


    return 0;
}
