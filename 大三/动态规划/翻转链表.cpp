#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
    int first,n,k;
    int addr,data[100005],next[100005];

    scanf("%d%d%d",&first,&n,&k);

    for(int i = 0; i < n; i++) {
        cin >> addr;
        cin >> data[addr] >> next[addr];
    }

    int sum = 0, listnode[100005],result[100005];;
    while(first != -1) {
        listnode[sum] = first;
        result[sum] = first;
        first = next[first];
        sum++;
    }

    for(int i = 0; i < sum-sum%k; i++)
        result[i] = listnode[i/k*k+k-1-i%k];

    int i;
    for(i = 0; i < sum-1; i++)
        printf("%05d %d %05d\n",result[i],data[result[i]],result[i+1]);

    printf("%05d %d -1\n",result[i],data[result[i]]);

    return 0;
}
