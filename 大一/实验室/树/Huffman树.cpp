#include<stdio.h>
#define M 999999
#define N 1001
struct node
{
    int wei;
    int vist;
    int parent;

}s[2001];

int main()
{

    int n,i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&s[i].wei);
        s[i].vist=0;
        s[i].parent=-1;
    }
    if(n==1)
    {
        printf("%d\n",s[0].wei);
        return 0;
    }

    int n1,n2,min1,min2;
    for(i=n; i<2*n-1; i++)
    {
        n1=n2=-1;
        min1=min2=M;

        for(j=0; j<i; j++)
            if(s[j].vist==0)
                if(s[j].wei<min1)
                {
                    min2=min1;
                    n2=n1;
                    min1=s[j].wei;
                    n1=j;
                }
                else if(s[j].wei<min2)
                {
                    min2=s[j].wei;
                    n2=j;
                }
        s[i].wei=s[n1].wei+s[n2].wei;
        s[i].vist=0;
        s[i].parent=-1;
        s[n1].vist=1;
        s[n1].parent=i;
        s[n2].vist=1;
        s[n2].parent=i;
    }

    int t=0;
    for(i=0; i<n; i++)
    {
        j=0;
        int k=i;
        while(s[k].parent!=-1)
        {
            k=s[k].parent;
            j++;
        }
        t+=j*s[i].wei;
    }
    printf("%d\n",t);
}
