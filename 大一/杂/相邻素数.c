#include<stdio.h>
#include"math.h"
int judge(int m)
  {

    int k,i;
    k=sqrt(m);

    if(m==1)
    return 0;

    if(m==2||m==3)
    return 1;

    if(m%6!=1&&m%6!=5)
    return 0;

    for(i=5; i<=k; i+=6)
     if(m%i==0||m%(i+2)==0)
        return 0;
    return 1;
}

int main()
{
    int n,m,j,i;

    scanf("%d",&n);

    while(n)
    {
        scanf("%d",&m);
        if(m==1)
        {
            printf("2 1\n");
            continue;
        }
        i=j=m;

        while(1)
        {
            if(judge(i))
            {
                printf("%d %d\n",i,m-i);
                break;
            }
            if(judge(j))
            {
                printf("%d %d\n",j,j-m);
                break;
            }
            i--;
            j++;
        }
        n--;
    }
 return 0;
}
