#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>

using namespace std;
int main()
{
    priority_queue<long long,vector<long long>,greater<long long> > q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        q.push(m);
    }
    long long sum=0;
    while(n>=2)
    {
        int a,b;
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        q.push(a+b);
        sum+=a+b;
        n--;
    }
    cout<<sum<<endl;
return 0;
}
