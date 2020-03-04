#include<cstdio>
#include<iostream>

using namespace std;

int mod[600000];

int main()
{
    int n;
    while(cin >> n, n != 0)
    {
        mod[1] = 1;
        int i;
        for(i = 2; mod[i-1] != 0; i++)
            mod[i] = (mod[i/2]*10+i%2)%n;
        i--;
        int j = 0;
        while(i)
        {
            mod[j++] = i % 2;
            i /= 2;
        }
        while(j)
            cout << mod[--j];
        cout << endl;
    }
    return 0;
}
