#include<stdio.h>
#include<string.h>
#define maxn 1000010

int next[maxn];
char t[maxn];

int m,n,sum=1;
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
    while( scanf("%d",&m),m )
    {
        scanf("%s",t);
        get_next();
        printf("Test case #%d\n", sum++);
        int i;
        for(i=1; i <= m; i++)
        {
            n=i-next[i];
            if(i != n && i%n == 0)
                printf("%d %d\n",i,i/n);
        }
        printf("\n");

    }

}
