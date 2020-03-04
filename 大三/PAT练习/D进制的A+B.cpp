#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

void print(long long sum,int d)
{
    if(sum == 0)
        return;

    int n = sum % d;

    print(sum/d,d);
    printf("%d",n);

}

int main()
{

    long long a,b,sum;
    int d;
    stack<int> s;

    scanf("%lld%lld%d",&a,&b,&d);

    sum = a + b;

    while(sum)
    {
        s.push(sum%d);
        sum /= d;
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    //print(sum,d);
    return 0;
}
