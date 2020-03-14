#include<cstdio>
#include<iostream>
#include<map>

using namespace std;
int a[1005];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int res = 0;
        map<int,int> m;
        for(int i = 0;i < n;i++)
            cin >> a[i];
        for(int i = 0;i < n;i++)
        {
            for(int j = i+1;j < n;j++)
            {
                int sum = a[i] + a[j];
                if(!m.count(sum))
                    m[sum] = 1;
                else
                    m[sum]++;
                res = max(m[sum],res);
            }
        }
        cout << res << endl;
    }
    return 0;
}

