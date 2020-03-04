#include <stdio.h>
#include <stdlib.h>
#define maxn 10000

struct node
{
    long value;
    long pos;

}s[maxn+1];

long a[maxn+1],c[maxn+1];

int cmp(const void *a,const void *b)
{
    if ((*(struct node *)a).value<(*(struct node *)b).value)
        return -1;
    else
        return 1;
}

int main()
{
    long n,i,t,v;
    long long ans;
    scanf("%ld",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%ld",&s[i].value);
        s[i].pos=i;
    }
    qsort(s+1,n,sizeof(struct node),cmp);

    t=1;
    for (i=1;i<=n;i++)
    {
        t++;
        a[s[i].pos]=t;
        while (i<n && s[i].value==s[i+1].value)
        {
            i++;
            a[s[i].pos]=t;
        }
    }

    for (i=1;i<=t;i++)
        c[i]=0;
    ans=0;
    for (i=n;i>=1;i--)
    {

        v=a[i]-1;
        while (v>0)
        {
            ans+=c[v];
            v=v-(v & (-v));
        }

        v=a[i];
        while (v<=t)
        {
            c[v]++;
            v=v+(v & (-v));
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
#include<stdio.h>
unsigned long c[10000000];
unsigned long n,ans;
void modify(int k)
{
    for(;k < 10000110; k+=(-k)&k)
        c[k]+=1;
}
int get(int k)
{
    int s;
    for(s=0;k>0;k-=-(k)&k)
        s+=c[k];
    return s;
}

int main()
{
    scanf("%d",&n);
    int i,k;
    ans=0;
    for(i=1; i<=n; i++)
    {
        scanf("%d",&k);
        modify(k);
        ans+=i-get(k);
    }
    printf("%d\n",ans);
    return 0;
}*/
