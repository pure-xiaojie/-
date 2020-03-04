#include<stdio.h>
#include<string.h>

#define maxn 1000005
#define maxn2 10005

int s[maxn],t[maxn2];
int next[maxn2];

int m,n;

int kmp_index()
{
    int j=0;
    for(int i=0;i<m;i++)
    {
       while(j!=-1&&s[i]!=t[j])
            j=next[j];
       j++;
       if(j==n)
           return i-n+2;
    }
    return -1;
}
void get_next()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<n)
    {
        if(j==-1||t[i]==t[j])
            next[++i]=++j;
        else
            j=next[j];
    }
}

int main()
{
    int x;
    scanf("%d",&x);
    while(x--)
    {
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
            scanf("%d",&s[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&t[i]);
        get_next();
       printf("%d\n",kmp_index());
    }

}
