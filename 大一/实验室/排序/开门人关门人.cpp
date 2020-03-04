#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
#define type 1000
#define MAX 100

int a[type];

struct node
{
    char num[20];
    char in[10];
    char out[10];

} r[MAX];

bool cmp1(node a,node b)
{
    return strcmp(a.in,b.in)<0;
}
bool cmp2(node a,node b)
{
    return strcmp(a.out,b.out)>0;
}
int main()
{
    int n,m,i,j;
    while(~scanf("%d",&n))
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&m);
            for(j=0; j<m; j++)
                scanf("%s%s%s",r[j].num,r[j].in,r[j].out);
            sort(r,r+m,cmp1);
            printf("%s ",r[0].num);

            sort(r,r+m,cmp2);
            printf("%s\n",r[0].num);
        }
    }
    return 0;
}

