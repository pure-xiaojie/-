#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
int n,l,h;

struct man {
    long num;       //ѧ��
    int score1;     //�·�
    int score2;     //�ŷ�
    int sum;        //�ܷ�
    int lavel;      //�ȼ�   1���²�>=h ...
}li[100100];

bool cmp(man a,man b)   //�Զ���������
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

    struct man maxli[100010];   //����²ž�����L����

    int t = 0;
    for(int i = 0; i < n; i++) {
        scanf("%ld%d%d",&li[i].num,&li[i].score1,&li[i].score2);
        //ɸѡ
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
