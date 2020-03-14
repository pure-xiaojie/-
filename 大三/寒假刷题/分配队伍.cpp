#include<cstdio>
#include<iostream>

using namespace std;
long long a,b,c;

int main() {
    int n;
    scanf("%d",&n);
    while(n--) {
        scanf("%lld%lld%lld",&a,&b,&c);
        cout << min(a,min(b,(a+b+c)/3)) << endl;
    }

    return 0;
}

