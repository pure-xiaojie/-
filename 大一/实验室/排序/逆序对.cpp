#include <stdio.h>
#include <stdlib.h>
#define maxn 100000

long a[maxn+1],t[maxn+1];

long long ans=0;

void mergesort(long l,long r)
{
    if (l==r)
        return ;
    long mid,x,y,z,i;
    mid=(l+r)/2;
    mergesort(l,mid);
    mergesort(mid+1,r);
    for (i=l;i<=r;i++)
        t[i]=a[i];
    x=l;
    y=mid+1;
    z=l;
    while (x<=mid && y<=r)
    {
        if (t[x]<=t[y])
        {
            a[z]=t[x];
            x++;
            ans+=(y-mid-1);
        }
        else if (t[x]>t[y])
        {
            a[z]=t[y];
            y++;
        }
        z++;
    }
    if (x<=mid)
    {
        ans+=(mid-x+1)*(r-mid);
        while (z<=r)
        {
            a[z]=t[x];
            x++;
            z++;
        }
    }
    else
    {
        while (z<=r)
        {
            a[z]=t[y];
            y++;
            z++;
        }
    }
}

int main()
{
    long n,i;
    scanf("%ld",&n);
    for (i=1;i<=n;i++)
        scanf("%ld",&a[i]);
    mergesort(1,n);
    printf("%lld\n",ans);
    return 0;
}

/*#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=40005;
int n,a[N],c[N],ans;

void msort(int l,int r)
{
    if(l==r)
        return;
    int mid=(l+r)>>1;
    msort(l,mid);
    msort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
            c[k++]=a[i++];
        else
        {
            c[k++]=a[j++];
            ans+=(mid-i+1);
        }
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=r)
        c[k++]=a[j++];
    for(i=l; i<=r; i++)
        a[i]=c[i];
}

int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    msort(1,n);

    cout<<ans<<endl;

    return 0;
}

#include<stdio.h>

#define type long long
#define max1 100001
type a[max1];

int main()
{
    type n,m,i,k;
    while(~scanf("%lld",&n))
    {
       m=0;
       for(i=0; i<n; i++)
         scanf("%lld",&a[i]);
       for(i=0; i<n-1; i++)
         for(k=i+1; k<n; k++)
         if(a[i] > a[k])
            m++;
        printf("%lld\n",m);
    }
    return 0;
}*/
