#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int t = 0,sum = 0;
    for(int i = a; i <= b; i++)
    {
        sum += i;
        printf("%5d",i);
        t++;
        if(t % 5 == 0)
            cout << endl;
    }
    cout << endl << "sum = " << sum;
    return 0;
}
