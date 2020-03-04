#include<stdio.h>
#include<string.h>
#define maxn 1000010

char t[maxn];
int next[maxn];

int m;
void get_next()
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<m)
    {
        if(j==-1||t[i]==t[j])
            next[++i]=++j;
        else
            j=next[j];
    }
}

int main()
{
    while( ~scanf("%s",t) )
    {
        if(strcmp(t, ".") == 0)
            break;
        m = strlen(t);
        get_next();
        if(m%(m-next[m]) == 0)
            printf("%d\n",m/(m-next[m]));
        else
            printf("1\n");
    }
}
