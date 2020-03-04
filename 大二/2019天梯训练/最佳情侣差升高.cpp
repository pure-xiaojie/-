#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n;
    char sex;
    float high;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> sex >> high;
        if(sex == 'M')
            printf("%.2f\n",high/1.09);
        else if(sex == 'F')
            printf("%.2f\n",high*1.09);
    }
    return 0;
}
