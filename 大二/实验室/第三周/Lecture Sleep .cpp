#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int a[100005];
int book[100005];

int n,k;

int main()
{
    int sum=0;
    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int j=1; j<=n; j++)
        cin>>book[j];
    for(int j=1; j<=n; j++)
        if(book[j])
            sum+=a[j];

    int maxi=0;
    int sum2=0;

    for(int i=1; i<=n; i++)
    {
        if(!book[i])
            sum2+=a[i];
        if(i-k>0&&!book[i-k])
            sum2-=a[i-k];
        maxi=max(maxi,sum2);
    }

    cout << sum+maxi << endl;

    return 0;
}
