#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n,sex[51];
    char name[51][10];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> sex[i] >> name[i];

    for(int i = 0; i < n/2; i++)
    {
        cout << name[i] << ' ';
        for(int j  = n-1; j > n/2-1; j--)
            if(sex[j] != sex[i] && sex[j] != 2)
            {
              cout << name[j] << endl;
              sex[j] = 2;
              break;

            }
    }
    return 0;
}
