#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define MAX 100000
#define type long long

struct node
{
    char num[7];
    char name[10];
    int score;

} a[MAX];

bool cmp1(node a,node b)
{
    return strcmp(a.num,b.num)<0;
}
bool cmp2(node a,node b)
{
    if(strcmp(a.name,b.name)==0)
    {
        return strcmp(a.num,b.num)<0;
    }
    return strcmp(a.name,b.name)<0;


}
bool cmp3(node a,node b)
{
    if(a.score==b.score)
    {
       return strcmp(a.num,b.num)<0;
    }
    return a.score<b.score;
}

int main()
{
    type n,m,i,j=0;
    while(~scanf("%lld%lld",&n,&m),n)
    {
        j++;
        for(i=0; i<n; i++)
          scanf("%s %s %d",a[i].num,a[i].name,&a[i].score);
        switch(m)
        {
            case 1:sort(a,a+n,cmp1);
                   break;
            case 2:sort(a,a+n,cmp2);
                   break;
            case 3:sort(a,a+n,cmp3);
                   break;
        }
        printf("Case %d:\n",j);
        for(i=0; i<n; i++)
            printf("%s %s %d\n",a[i].num,a[i].name,a[i].score);

    }
    return 0;
}

