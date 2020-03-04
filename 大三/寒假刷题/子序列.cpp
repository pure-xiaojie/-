#include<cstdio>
#include<iostream>

using namespace std;
int n;
char str[200005];

int main()
{

    int n;
    while(~scanf("%d",&n))
    {
        cin >> str;
        int sum[5] = {0};
        for(int i = 0; i < n; i++) {
            if(str[i] == 'x')
                sum[0]++;
            else if(str[i] == 't' && sum[1] < sum[0])
                sum[1]++;
            else if(str[i] == 'C' && sum[2] < sum[1])
                sum[2]++;
            else if(str[i] == 'p' && sum[3] < sum[2])
                sum[3]++;
            else if(str[i] == 'c' && sum[4] < sum[3])
                sum[4]++;
        }
        int res = n+1;
        for(int i = 0; i < 5; i++) {
            if(res > sum[i])
                res = sum[i];
        }
        cout << res << endl;
    }
    return 0;
}
