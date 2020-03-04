#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long a[150005];

int main() {
    int n;
    while(~scanf("%d",&n)) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }

        long long minNum = a[n-1];

        for(int i = n-1; i >= 0; i--) {
            minNum = min(minNum,a[i]);
            if(a[i] > minNum)
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
