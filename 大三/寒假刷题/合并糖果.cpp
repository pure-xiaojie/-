#include<cstdio>
#include<iostream>

using namespace std;
long long num[100005];
long long n,k;

int main()
{
    int t,x = 1;
    scanf("%d",&t);

    while(t--)
    {
        long long sum = 0,res = 0;
        scanf("%lld%lld",&n,&k);
        for(int i = 0; i < n; i++) {
            scanf("%lld",&num[i]);
            sum += num[i];
        }
        if(sum % k != 0)
            printf("Case #%d: %d\n",x++,-1);
        else {
            int m = sum / k;
            for(int i = 0; i < n; i++) {
                if(num[i] > m) {
                    res += num[i] / m;
                    int h = num[i] % m;
                    if(h == 0) {
                        res--;
                    }
                    else {
                        num[i+1] += h;
                        res++;
                    }
                }else if(num[i] < m){
                    res++;
                    num[i+1] += num[i];
                }
            }
            printf("Case #%d: %lld\n",x++,res);

        }

    }
    return 0;
}
