#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int n,num[101];
    while(~scanf("%d",&n))
    {
        for(int i = 1; i <= n; i++)
            cin >> num[i];
        int sum1 = 0,t1, sum2 = 0,t2;

        for(int i = 1; i <= n; i++)
        if(num[i] < 0) {
            if(num[i] * -1 % 2 == 0) {
                sum2++;
                t2 = i;
            } else {
                sum1++;
                t1 = i;
            }
        } else {
           if(num[i] % 2 == 0) {
                sum2++;
                t2 = i;
            } else {
                sum1++;
                t1 = i;
            }
        }
        if(sum1 == 1)
            cout << t1 << endl;
        else if(sum2 == 1)
            cout << t2 << endl;
    }
    return 0;
}
