#include<cstdio>
#include<iostream>

using namespace std;
double res[1000000];

int main()
{
    res[1] = 1.0;
    res[2] = 1.25;
    for(int i = 3; i < 1000000; i++)
        res[i] = 1.0/(i*i) + res[i-1];

    int n;
    while(cin >> n)
    {
        if(n < 1000000)
            printf("%.5f\n",res[n]);
    }
    return 0;
}
