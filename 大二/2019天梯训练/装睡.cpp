#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n;
    char name[10][4];
    int a[10],b[10];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> name[i] >> a[i] >> b[i];
    for(int i = 0; i < n; i++)
        if(a[i]<15 || a[i]>20 || b[i] < 50 || b[i] > 70)
            cout << name[i] << endl;
    return 0;
}
