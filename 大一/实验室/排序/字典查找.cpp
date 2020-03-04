#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

#define MAX 100001
#define type long long

struct node
{
    char num[11];
    char name[11];

} a[MAX];

bool cmp1(node a,node b)
{
    return strcmp(a.name,b.name)<0;
}

int main()
{
    type n,m,i=0;

    char str[11];
    while(gets(str))
    {
        if(str[0]=='\0')
            break;

        sscanf(str,"%s%s",a[i].num,a[i].name);
        i++;
    }

    char c[11];
    sort(a,a+i,cmp1);

    while(~scanf("%s",c))
    {
        type j,left=0,right=i,mid;
        int t=0;
        while(left<right)
        {
            mid=(left+right)/2;
            if(strcmp(c,a[mid].name) < 0)
                right=mid;
            else if(strcmp(c,a[mid].name) > 0)
                left=mid+1;
            else
            {
                printf("%s\n",a[mid].num);
                t=1;
                break;
            }

        }
        if(!t)
        printf("eh\n");

    }
    return 0;
}

