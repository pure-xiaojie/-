#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

const int maxn = 1010;
int x[maxn],y[maxn];
priority_queue<long long> q;

int main()
{
    int n,k1,k2;
    while(cin >> n >> k1 >> k2)
    {
        while(!q.empty())
            q.pop();
        for(int i=0; i<n; i++)
            cin >> x[i];

        for(int i=0; i<n; i++)
        {
            cin >> y[i];
            q.push(abs(x[i]-y[i]));
        }

        int k = k1 + k2,temp;
        while(k > 0)
        {
            temp = q.top();
            if(temp == 0) temp ++;
            else temp --;
            q.pop();
            q.push(temp);
            k--;
        }
        long long sum = 0;
        while(!q.empty())
        {
            sum += q.top() * q.top();
            q.pop();
        }
        cout << sum << endl;
    }

    return 0;
}
