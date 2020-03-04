#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int a[1005];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++)
            cin >> a[i];

        int m=1,sum=0;
        int max=0;
        for(int i=1; i<n; i++)
        {

            if(a[i]-a[i-1]==1)
            {
                m++;
                if(a[i-1]==1 || a[i] == 1000)
                {
                    m++;
                }
                if(i==n-1)
                {
                    sum=sum+m-2>0?m-2:0;
                    max=max>sum?max:sum;
                }
            }
            else
            {
                sum=sum+m-2>0?m-2:0;
                m=1;
                max=max>sum?max:sum;
                sum=0;
            }
        }
        cout << max << endl;

    }
    return 0;
}
