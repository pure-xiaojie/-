#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
int n,l,h;

struct man {
    long num;       //学号
    int score1;     //德分
    int score2;     //才分
    int sum;        //总分
    int lavel;      //等级   1级德才>=h ...
}li[100100];

bool cmp(man a,man b)   //自定义排序函数
{
    if (a.lavel != b.lavel)
        return a.lavel < b.lavel;
    else if (a.sum != b.sum)
        return a.sum > b.sum;
    else if (a.score1 != b.score1)
        return a.score1 > b.score1;
    else
        return a.num < b.num;

}

int main() {
    scanf("%d%d%d",&n,&l,&h);

    struct man maxli[100010];   //满足德才均大于L的人

    int t = 0;
    for(int i = 0; i < n; i++) {
        scanf("%ld%d%d",&li[i].num,&li[i].score1,&li[i].score2);
        //筛选
        if(li[i].score1 >= l && li[i].score2 >= l) {
            maxli[t] = li[i];
            maxli[t].sum = maxli[t].score1+maxli[t].score2;
            if(maxli[t].score1 >= h && maxli[t].score2 >= h)
                maxli[t].lavel=1;
            else if(maxli[t].score1 >= h && maxli[t].score2 < h)
                maxli[t].lavel=2;
            else if(maxli[t].score1 < h && maxli[t].score2 < h && maxli[t].score1 >= maxli[t].score2)
                maxli[t].lavel=3;
            else
                maxli[t].lavel=4;
            t++;
        }

    }

    sort(maxli,maxli+t,cmp);
    printf("%d\n",t);

    for(int i = 0; i < t; i++)
        printf("%ld %d %d\n",maxli[i].num,maxli[i].score1,maxli[i].score2);
    return 0;
}
