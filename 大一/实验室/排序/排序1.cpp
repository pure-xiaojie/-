#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stack>
#include<queue>
using namespace std;
#define type long long
int a[1001],n;

bool compare(int a,int b)
{
    return a<b;
}
void print()
{
    for(int i=0; i<n; i++)
    {
         cout<<a[i];
         if(i<n-1)
            cout<<" ";
    }

}
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        cin >> n;
        for(i=0; i<n; i++)
         cin >> a[i];
        sort(a,a+n,compare);
        print();
        cout<<endl;
    }

    return 0;
}

