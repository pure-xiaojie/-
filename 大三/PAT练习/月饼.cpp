#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

struct node
{
    int amount;
    int money;
    double avemoney;

}w[1005];

bool cmp(node a, node b)
{
    return a.avemoney > b.avemoney;

}

int main()
{
    int n,sum;
    double summoney = 0;

    scanf("%d%d",&n,&sum);
    for(int i = 0; i < n; i++)
        scanf("%d",&w[i].amount);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&w[i].money);
        w[i].avemoney =  w[i].money*1.0 / w[i].amount;
    }

    sort(w,w+n,cmp);

    int t = 0;
    while(sum > 0)
    {
        if(sum > w[t].amount)
            summoney += w[t].money;
        else
            summoney += sum * w[t].avemoney;
        sum -= w[t].amount;
        t++;

    }

    printf("%.2lf",summoney);
    return 0;
}
