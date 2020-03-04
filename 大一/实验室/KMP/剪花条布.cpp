#include<stdio.h>
#include<string.h>
#define maxn 1010

int next[maxn];
char s[maxn],t[maxn];

int m,n,sum;

int kmp_index(int x)
{
    int i,j=0;
    for(i=x;i<m;i++)
    {
       while(j!=-1&&s[i]!=t[j])
            j=next[j];
       j++;
       if(j==n)
       {
            sum++;
            break;
       }
    }
    if(j==n)
        kmp_index(i+1);
    return 0;
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
    while( scanf("%s",s),s[0] != '#')
    {
        scanf("%s",t);
        sum=0;
        m=strlen(s);
        n=strlen(t);
        get_next();
        kmp_index(0);
        printf("%d\n",sum);
    }
    return 0;
}
